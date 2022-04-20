#include <math.h>
#include <stdlib.h>
#include <string.h>
#ifndef __cplusplus
#    include <stdbool.h>
#endif

#include <sndfile.h>

#include <array>
#include <concepts>

#include "lv2/lv2plug.in/ns/ext/atom/util.h"
#include "lv2/lv2plug.in/ns/ext/midi/midi.h"
#include "lv2/lv2plug.in/ns/ext/patch/patch.h"
#include "lv2/lv2plug.in/ns/ext/state/state.h"
#include "lv2/lv2plug.in/ns/ext/urid/urid.h"
#include "lv2/lv2plug.in/ns/lv2core/lv2.h"

#include "lv2/lv2plug.in/ns/ext/log/log.h"
#include "lv2/lv2plug.in/ns/ext/midi/midi.h"
#include "lv2/lv2plug.in/ns/ext/state/state.h"

typedef struct {
	LV2_URID midi_Event;
} ArpURIs;

enum {
	MIDI_IN = 0,
	MIDI_OUT = 1
};

template<size_t N> struct Arpeggio {
	uint64_t start_time;
	uint64_t duration;
	std::array<int, N> notes;

	template<typename Func> requires std::invocable<Func&, uint64_t, int>
	void process(uint64_t from, uint64_t until, Func callback) {
		for (size_t i=0; i<N; i++) {
			auto valid_from = start_time + i * duration / N;
			auto valid_until = start_time + (i+1) * duration / N;

			if (from <= valid_from && valid_from < until) {
				callback(valid_from, notes[i]);
			}
		}
	}
};


struct Arp {
	LV2_URID_Map* map;

	LV2_Atom_Sequence const* in_port;
	LV2_Atom_Sequence* out_port;

	ArpURIs uris;

	uint64_t time = 0;

	Arpeggio<4> current_arpeggio;

	void connect_port(uint32_t port, void* data)
	{
		switch (port) {
		case MIDI_IN:
			in_port = (const LV2_Atom_Sequence*)data;
			break;
		case MIDI_OUT:
			out_port = (LV2_Atom_Sequence*)data;
			break;
		default:
			break;
		}
	}

	Arp(LV2_URID_Map* map)
		: map(map)
		, in_port(nullptr)
		, out_port(nullptr)
	{
		uris.midi_Event = map->map(map->handle, LV2_MIDI__MidiEvent);
	}

	void run(uint32_t sample_count) {
		struct MIDINoteEvent {
			LV2_Atom_Event event;
			std::array<uint8_t, 3> msg;
		};


		const uint32_t out_capacity = out_port->atom.size;
		lv2_atom_sequence_clear(out_port);
		out_port->atom.type = in_port->atom.type;

		uint64_t offset = 0;

		auto blah = [this, &out_capacity](uint64_t time, int transpose) {
			auto pitchbend = 0x2000 + transpose * 0x1FFF / 12;
			uint8_t msb = (pitchbend >> 7) & 0x7F;
			uint8_t lsb = pitchbend & 0x7F;

			MIDINoteEvent event;
			event.event.body.type = this->uris.midi_Event;
			event.event.body.size = 3;
			event.event.time.frames = time - this->time;
			event.msg = { 0xE0, lsb, msb };

			lv2_atom_sequence_append_event(this->out_port, out_capacity, &event.event);
		};
		
		LV2_ATOM_SEQUENCE_FOREACH(in_port, ev) {
			if (ev->body.type == uris.midi_Event) {
				current_arpeggio.process(time + offset, time + ev->time.frames, blah);
				offset = ev->time.frames;

				const uint8_t* const msg = (const uint8_t*)(ev + 1);

				switch (lv2_midi_message_type(msg)) {
					case LV2_MIDI_MSG_NOTE_ON:
					case LV2_MIDI_MSG_NOTE_OFF:
					{
						lv2_atom_sequence_append_event(out_port, out_capacity, ev);

						set_arpeggio(0x37, time + ev->time.frames);

						break;
					}
					default:
						// Forward all other MIDI events directly
						lv2_atom_sequence_append_event(out_port, out_capacity, ev);
						break;
				}
			}
		}
		
		current_arpeggio.process(time + offset, time + sample_count, blah);

		time += sample_count;
	}

	void set_arpeggio(uint8_t arpeggio, uint64_t timestamp) {
		current_arpeggio = Arpeggio<4> {
			timestamp,
			12000,
			{ 0, (arpeggio & 0xF0) >> 4, arpeggio & 0x0F, 0 }
		};
	}
};


static void connect_port(LV2_Handle instance, uint32_t port, void* data) {
	static_cast<Arp*>(instance)->connect_port(port, data);
}

static LV2_Handle instantiate(
	const LV2_Descriptor*     descriptor,
	double rate,
	const char* path,
	const LV2_Feature* const* features
) {
	LV2_URID_Map* map = nullptr;

	// Find urid:map feature
	for (int i = 0; features[i]; ++i) {
		if (!strcmp(features[i]->URI, LV2_URID__map)) {
			map = (LV2_URID_Map*)features[i]->data;
		}
	}
	if (!map) {
		fprintf(stderr, "Missing feature urid:map\n");
		return nullptr;
	}

	return static_cast<LV2_Handle>(new Arp(map));
}

static void cleanup(LV2_Handle instance) {
	delete static_cast<Arp*>(instance);
}

static void run(LV2_Handle instance, uint32_t sample_count) {
	static_cast<Arp*>(instance)->run(sample_count);
}

static void const* extension_data(const char* uri) {
	return nullptr;
}

static const LV2_Descriptor descriptor = {
	"https://windfis.ch/arp.lv2",
	instantiate,
	connect_port,
	nullptr,  // activate,
	run,
	nullptr,  // deactivate,
	cleanup,
	extension_data
};

LV2_SYMBOL_EXPORT LV2_Descriptor const* lv2_descriptor(uint32_t index) {
	switch (index) {
	case 0:
		return &descriptor;
	default:
		return nullptr;
	}
}
