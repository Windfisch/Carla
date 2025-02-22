#!/usr/bin/make -f
# Makefile for carla-bridges-plugin #
# --------------------------------- #
# Created by falkTX
#

CWD=..
MODULENAME=carla-bridge
include $(CWD)/Makefile.mk

# Workaround GCC bug
ifeq ($(TESTBUILD),true)
ifeq ($(USING_JUCE),true)
BUILD_CXX_FLAGS += -Wno-undef
# FIXME
BUILD_CXX_FLAGS += -Wno-deprecated-declarations
endif
endif

# ---------------------------------------------------------------------------------------------------------------------

BINDIR    := $(CWD)/../bin

ifeq ($(DEBUG),true)
OBJDIR    := $(CWD)/../build/bridges-plugin/Debug
MODULEDIR := $(CWD)/../build/modules/Debug
else
OBJDIR    := $(CWD)/../build/bridges-plugin/Release
MODULEDIR := $(CWD)/../build/modules/Release
endif

# ---------------------------------------------------------------------------------------------------------------------

BUILD_CXX_FLAGS += -DBUILD_BRIDGE -I. -I$(CWD) -I$(CWD)/backend -I$(CWD)/includes -I$(CWD)/modules -I$(CWD)/utils
BUILD_CXX_FLAGS += -I$(CWD)/backend/engine -I$(CWD)/backend/plugin

32BIT_FLAGS += -DBUILD_BRIDGE_ALTERNATIVE_ARCH
64BIT_FLAGS += -DBUILD_BRIDGE_ALTERNATIVE_ARCH
ARM32_FLAGS += -DBUILD_BRIDGE_ALTERNATIVE_ARCH

# ---------------------------------------------------------------------------------------------------------------------

LIBS_native   = $(MODULEDIR)/jackbridge.a
LIBS_arm32    = $(MODULEDIR)/jackbridge.arm32.a
LIBS_posix32  = $(MODULEDIR)/jackbridge.posix32.a
LIBS_posix64  = $(MODULEDIR)/jackbridge.posix64.a
ifeq ($(BUILDING_FOR_WINE),true)
LIBS_win32    = $(MODULEDIR)/jackbridge.win32e.a
LIBS_win64    = $(MODULEDIR)/jackbridge.win64e.a
else
LIBS_win32    = $(MODULEDIR)/jackbridge.win32.a
LIBS_win64    = $(MODULEDIR)/jackbridge.win64.a
endif
LINK_FLAGS   += $(JACKBRIDGE_LIBS)

LIBS_native  += $(MODULEDIR)/lilv.a
LIBS_arm32   += $(MODULEDIR)/lilv.arm32.a
LIBS_posix32 += $(MODULEDIR)/lilv.posix32.a
LIBS_posix64 += $(MODULEDIR)/lilv.posix64.a
LIBS_win32   += $(MODULEDIR)/lilv.win32.a
LIBS_win64   += $(MODULEDIR)/lilv.win64.a
LINK_FLAGS   += $(LILV_LIBS)

LIBS_native  += $(MODULEDIR)/rtmempool.a
LIBS_arm32   += $(MODULEDIR)/rtmempool.arm32.a
LIBS_posix32 += $(MODULEDIR)/rtmempool.posix32.a
LIBS_posix64 += $(MODULEDIR)/rtmempool.posix64.a
LIBS_win32   += $(MODULEDIR)/rtmempool.win32.a
LIBS_win64   += $(MODULEDIR)/rtmempool.win64.a
LINK_FLAGS   += $(RTMEMPOOL_LIBS)

LIBS_native  += $(MODULEDIR)/water.a
LIBS_arm32   += $(MODULEDIR)/water.arm32.a
LIBS_posix32 += $(MODULEDIR)/water.posix32.a
LIBS_posix64 += $(MODULEDIR)/water.posix64.a
LIBS_win32   += $(MODULEDIR)/water.win32.a
LIBS_win64   += $(MODULEDIR)/water.win64.a
LINK_FLAGS   += $(WATER_LIBS)

ifeq ($(USING_JUCE),true)
LIBS_native  += $(MODULEDIR)/juce_audio_basics.a
LIBS_posix32 += $(MODULEDIR)/juce_audio_basics.posix32.a
LIBS_posix64 += $(MODULEDIR)/juce_audio_basics.posix64.a
LIBS_win32   += $(MODULEDIR)/juce_audio_basics.win32.a
LIBS_win64   += $(MODULEDIR)/juce_audio_basics.win64.a
LINK_FLAGS   += $(JUCE_AUDIO_BASICS_LIBS)

LIBS_native  += $(MODULEDIR)/juce_audio_processors.a
LIBS_posix32 += $(MODULEDIR)/juce_audio_processors.posix32.a
LIBS_posix64 += $(MODULEDIR)/juce_audio_processors.posix64.a
LIBS_win32   += $(MODULEDIR)/juce_audio_processors.win32.a
LIBS_win64   += $(MODULEDIR)/juce_audio_processors.win64.a
LINK_FLAGS   += $(JUCE_AUDIO_PROCESSORS_LIBS)

LIBS_native  += $(MODULEDIR)/juce_core.a
LIBS_posix32 += $(MODULEDIR)/juce_core.posix32.a
LIBS_posix64 += $(MODULEDIR)/juce_core.posix64.a
LIBS_win32   += $(MODULEDIR)/juce_core.win32.a
LIBS_win64   += $(MODULEDIR)/juce_core.win64.a
LINK_FLAGS   += $(JUCE_CORE_LIBS)

LIBS_native  += $(MODULEDIR)/juce_data_structures.a
LIBS_posix32 += $(MODULEDIR)/juce_data_structures.posix32.a
LIBS_posix64 += $(MODULEDIR)/juce_data_structures.posix64.a
LIBS_win32   += $(MODULEDIR)/juce_data_structures.win32.a
LIBS_win64   += $(MODULEDIR)/juce_data_structures.win64.a
LINK_FLAGS   += $(JUCE_DATA_STRUCTURES_LIBS)

LIBS_native  += $(MODULEDIR)/juce_events.a
LIBS_posix32 += $(MODULEDIR)/juce_events.posix32.a
LIBS_posix64 += $(MODULEDIR)/juce_events.posix64.a
LIBS_win32   += $(MODULEDIR)/juce_events.win32.a
LIBS_win64   += $(MODULEDIR)/juce_events.win64.a
LINK_FLAGS   += $(JUCE_EVENTS_LIBS)

LIBS_native  += $(MODULEDIR)/juce_graphics.a
LIBS_posix32 += $(MODULEDIR)/juce_graphics.posix32.a
LIBS_posix64 += $(MODULEDIR)/juce_graphics.posix64.a
LIBS_win32   += $(MODULEDIR)/juce_graphics.win32.a
LIBS_win64   += $(MODULEDIR)/juce_graphics.win64.a
LINK_FLAGS   += $(JUCE_GRAPHICS_LIBS)

LIBS_native  += $(MODULEDIR)/juce_gui_basics.a
LIBS_posix32 += $(MODULEDIR)/juce_gui_basics.posix32.a
LIBS_posix64 += $(MODULEDIR)/juce_gui_basics.posix64.a
LIBS_win32   += $(MODULEDIR)/juce_gui_basics.win32.a
LIBS_win64   += $(MODULEDIR)/juce_gui_basics.win64.a
LINK_FLAGS   += $(JUCE_GUI_BASICS_LIBS)

ifeq ($(USING_JUCE_GUI_EXTRA),true)
LIBS_native  += $(MODULEDIR)/juce_gui_extra.a
LIBS_posix32 += $(MODULEDIR)/juce_gui_extra.posix32.a
LIBS_posix64 += $(MODULEDIR)/juce_gui_extra.posix64.a
LINK_FLAGS   += $(JUCE_GUI_EXTRA_LIBS)
endif
endif

ifeq ($(JACKBRIDGE_DIRECT),true)
LINK_FLAGS += $(JACK_LIBS)
endif

LINK_FLAGS += $(X11_LIBS)

# ---------------------------------------------------------------------------------------------------------------------

NATIVE_BUILD_FLAGS  = $(NATIVE_PLUGINS_FLAGS)
NATIVE_LINK_FLAGS   = $(NATIVE_PLUGINS_LIBS)

NATIVE_BUILD_FLAGS += $(LIBLO_FLAGS)
NATIVE_LINK_FLAGS  += $(LIBLO_LIBS)

NATIVE_BUILD_FLAGS += $(FLUIDSYNTH_FLAGS)
NATIVE_LINK_FLAGS  += $(FLUIDSYNTH_LIBS)

NATIVE_LINK_FLAGS  += $(MAGIC_LIBS)

LIBS_native        += $(MODULEDIR)/audio_decoder.a
LIBS_native        += $(MODULEDIR)/native-plugins.a
LIBS_native        += $(MODULEDIR)/sfzero.a
LIBS_native        += $(MODULEDIR)/zita-resampler.a

ifeq ($(HAVE_DGL),true)
LIBS_native        += $(MODULEDIR)/dgl.a
endif

ifeq ($(WIN32),true)
EXTRA_LINK_FLAGS   += -lole32 -lssp -mwindows
endif

# ---------------------------------------------------------------------------------------------------------------------

OBJS_native = \
	$(OBJDIR)/CarlaBridgePlugin.cpp.o \
	$(OBJDIR)/CarlaEngine.cpp.o \
	$(OBJDIR)/CarlaEngineClient.cpp.o \
	$(OBJDIR)/CarlaEngineData.cpp.o \
	$(OBJDIR)/CarlaEngineDummy.cpp.o \
	$(OBJDIR)/CarlaEngineGraph.cpp.o \
	$(OBJDIR)/CarlaEngineInternal.cpp.o \
	$(OBJDIR)/CarlaEngineNative.cpp.o \
	$(OBJDIR)/CarlaEngineOscSend.cpp.o \
	$(OBJDIR)/CarlaEnginePorts.cpp.o \
	$(OBJDIR)/CarlaEngineThread.cpp.o \
	$(OBJDIR)/CarlaEngineJack.cpp.o \
	$(OBJDIR)/CarlaEngineBridge.cpp.o \
	$(OBJDIR)/CarlaPlugin.cpp.o \
	$(OBJDIR)/CarlaPluginBridge.cpp.o \
	$(OBJDIR)/CarlaPluginInternal.cpp.o \
	$(OBJDIR)/CarlaPluginJack.cpp.o \
	$(OBJDIR)/CarlaPluginNative.cpp.o \
	$(OBJDIR)/CarlaPluginLADSPADSSI.cpp.o \
	$(OBJDIR)/CarlaPluginLV2.cpp.o \
	$(OBJDIR)/CarlaPluginVST2.cpp.o \
	$(OBJDIR)/CarlaPluginVST3.cpp.o \
	$(OBJDIR)/CarlaPluginAU.cpp.o \
	$(OBJDIR)/CarlaPluginJuce.cpp.o \
	$(OBJDIR)/CarlaPluginFluidSynth.cpp.o \
	$(OBJDIR)/CarlaPluginSFZero.cpp.o \
	$(OBJDIR)/CarlaStandalone.cpp.o

OBJS_lv2 = $(OBJS_native) \
	$(OBJDIR)/CarlaBridgeSingleLV2.cpp.o

OBJS_arch = \
	$(OBJDIR)/CarlaBridgePlugin.cpp.arch.o \
	$(OBJDIR)/CarlaEngine.cpp.arch.o \
	$(OBJDIR)/CarlaEngineClient.cpp.arch.o \
	$(OBJDIR)/CarlaEngineData.cpp.arch.o \
	$(OBJDIR)/CarlaEngineInternal.cpp.arch.o \
	$(OBJDIR)/CarlaEnginePorts.cpp.arch.o \
	$(OBJDIR)/CarlaEngineThread.cpp.arch.o \
	$(OBJDIR)/CarlaEngineJack.cpp.arch.o \
	$(OBJDIR)/CarlaEngineBridge.cpp.arch.o \
	$(OBJDIR)/CarlaPlugin.cpp.arch.o \
	$(OBJDIR)/CarlaPluginBridge.cpp.arch.o \
	$(OBJDIR)/CarlaPluginInternal.cpp.arch.o \
	$(OBJDIR)/CarlaPluginLADSPADSSI.cpp.arch.o \
	$(OBJDIR)/CarlaPluginLV2.cpp.arch.o \
	$(OBJDIR)/CarlaPluginVST2.cpp.arch.o \
	$(OBJDIR)/CarlaPluginVST3.cpp.arch.o \
	$(OBJDIR)/CarlaPluginAU.cpp.arch.o \
	$(OBJDIR)/CarlaPluginJuce.cpp.arch.o \
	$(OBJDIR)/CarlaStandalone.cpp.arch.o

OBJS_arm32   = $(OBJS_arch:%.arch.o=%.arm32.o)
OBJS_posix32 = $(OBJS_arch:%.arch.o=%.posix32.o)
OBJS_posix64 = $(OBJS_arch:%.arch.o=%.posix64.o)
OBJS_win32   = $(OBJS_arch:%.arch.o=%.win32.o)
OBJS_win64   = $(OBJS_arch:%.arch.o=%.win64.o)

# ---------------------------------------------------------------------------------------------------------------------

all: native

# ---------------------------------------------------------------------------------------------------------------------

clean:
	rm -f $(OBJDIR)/*.o
	rm -f $(BINDIR)/$(MODULENAME)-native
	rm -f $(BINDIR)/$(MODULENAME)-posix32
	rm -f $(BINDIR)/$(MODULENAME)-posix64
	rm -f $(BINDIR)/$(MODULENAME)-win*.exe

debug:
	$(MAKE) DEBUG=true

# ---------------------------------------------------------------------------------------------------------------------

native:  $(BINDIR)/$(MODULENAME)-native$(APP_EXT) $(BINDIR)/$(MODULENAME)-lv2$(LIB_EXT)
arm32:   $(BINDIR)/$(MODULENAME)-arm32
posix32: $(BINDIR)/$(MODULENAME)-posix32
posix64: $(BINDIR)/$(MODULENAME)-posix64
win32:   $(BINDIR)/$(MODULENAME)-win32.exe
win64:   $(BINDIR)/$(MODULENAME)-win64.exe

# ---------------------------------------------------------------------------------------------------------------------
# linking

$(BINDIR)/$(MODULENAME)-native$(APP_EXT): $(OBJS_native) $(LIBS_native)
	-@mkdir -p $(BINDIR)
	@echo "Linking $(MODULENAME)-native$(APP_EXT)"
	$(SILENT)$(CXX) $(OBJS_native) $(BUILD_CXX_FLAGS) $(LIBS_START) $(LIBS_native) $(LIBS_END) $(LINK_FLAGS) $(EXTRA_LINK_FLAGS) $(NATIVE_LINK_FLAGS) -o $@

$(BINDIR)/$(MODULENAME)-lv2$(LIB_EXT): $(OBJS_lv2) $(LIBS_native)
	-@mkdir -p $(BINDIR)
	@echo "Linking $(MODULENAME)-lv2$(LIB_EXT)"
	$(SILENT)$(CXX) $(OBJS_lv2) $(BUILD_CXX_FLAGS) $(LIBS_START) $(LIBS_native) $(LIBS_END) $(SHARED) $(LINK_FLAGS) $(NATIVE_LINK_FLAGS) -o $@

$(BINDIR)/$(MODULENAME)-arm32: $(OBJS_arm32) $(LIBS_arm32)
	-@mkdir -p $(BINDIR)
	@echo "Linking $(MODULENAME)-arm32"
	$(SILENT)$(CXX) $(OBJS_arm32) $(BUILD_CXX_FLAGS) $(LIBS_START) $(LIBS_arm32) $(LIBS_END) $(LINK_FLAGS) $(ARM32_FLAGS) -o $@

$(BINDIR)/$(MODULENAME)-posix32: $(OBJS_posix32) $(LIBS_posix32)
	-@mkdir -p $(BINDIR)
	@echo "Linking $(MODULENAME)-posix32"
	$(SILENT)$(CXX) $(OBJS_posix32) $(BUILD_CXX_FLAGS) $(LIBS_START) $(LIBS_posix32) $(LIBS_END) $(LINK_FLAGS) $(32BIT_FLAGS) -o $@

$(BINDIR)/$(MODULENAME)-posix64: $(OBJS_posix64) $(LIBS_posix64)
	-@mkdir -p $(BINDIR)
	@echo "Linking $(MODULENAME)-posix64"
	$(SILENT)$(CXX) $(OBJS_posix64) $(BUILD_CXX_FLAGS) $(LIBS_START) $(LIBS_posix64) $(LIBS_END) $(LINK_FLAGS) $(64BIT_FLAGS) -o $@

$(BINDIR)/$(MODULENAME)-win32.exe: $(OBJS_win32) $(LIBS_win32)
	-@mkdir -p $(BINDIR)
	@echo "Linking $(MODULENAME)-win32.exe"
	$(SILENT)$(CXX) $(OBJS_win32) $(BUILD_CXX_FLAGS) $(LIBS_START) $(LIBS_win32) $(LIBS_END) $(LINK_FLAGS) $(EXTRA_LINK_FLAGS) $(32BIT_FLAGS) -o $@

$(BINDIR)/$(MODULENAME)-win64.exe: $(OBJS_win64) $(LIBS_win64)
	-@mkdir -p $(BINDIR)
	@echo "Linking $(MODULENAME)-win64.exe"
	$(SILENT)$(CXX) $(OBJS_win64) $(BUILD_CXX_FLAGS) $(LIBS_START) $(LIBS_win64) $(LIBS_END) $(LINK_FLAGS) $(EXTRA_LINK_FLAGS) $(64BIT_FLAGS) -o $@

# ---------------------------------------------------------------------------------------------------------------------
# native

ifeq ($(MACOS),true)
$(OBJDIR)/CarlaPluginVST2.cpp.o: $(CWD)/backend/plugin/CarlaPluginVST2.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling CarlaPluginVST2.cpp (bridge)"
	$(SILENT)$(CXX) $< $(BUILD_CXX_FLAGS) $(NATIVE_BUILD_FLAGS) -ObjC++ -c -o $@

$(OBJDIR)/CarlaPluginJuce.cpp.o: $(CWD)/backend/plugin/CarlaPluginJuce.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling CarlaPluginJuce.cpp (bridge)"
	$(SILENT)$(CXX) $< $(BUILD_CXX_FLAGS) $(NATIVE_BUILD_FLAGS) -ObjC++ -c -o $@

$(OBJDIR)/CarlaStandalone.cpp.o: $(CWD)/backend/CarlaStandalone.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling CarlaStandalone.cpp (bridge)"
	$(SILENT)$(CXX) $< $(BUILD_CXX_FLAGS) $(NATIVE_BUILD_FLAGS) -ObjC++ -c -o $@

$(OBJDIR)/CarlaBridgePlugin.cpp.o: CarlaBridgePlugin.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling $<"
	$(SILENT)$(CXX) $< $(BUILD_CXX_FLAGS) $(NATIVE_BUILD_FLAGS) -ObjC++ -c -o $@
else
$(OBJDIR)/CarlaStandalone.cpp.o: $(CWD)/backend/CarlaStandalone.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling CarlaStandalone.cpp (bridge)"
	$(SILENT)$(CXX) $< $(BUILD_CXX_FLAGS) $(NATIVE_BUILD_FLAGS) -c -o $@

$(OBJDIR)/CarlaBridgePlugin.cpp.o: CarlaBridgePlugin.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling $<"
	$(SILENT)$(CXX) $< $(BUILD_CXX_FLAGS) $(NATIVE_BUILD_FLAGS) -c -o $@
endif

$(OBJDIR)/CarlaBridgeSingleLV2.cpp.o: CarlaBridgeSingleLV2.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling $<"
	$(SILENT)$(CXX) $< $(BUILD_CXX_FLAGS) $(NATIVE_BUILD_FLAGS) -c -o $@

$(OBJDIR)/CarlaPlug%.cpp.o: $(CWD)/backend/plugin/CarlaPlug%.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling CarlaPlug$*.cpp (bridge)"
	$(SILENT)$(CXX) $< $(BUILD_CXX_FLAGS) $(NATIVE_BUILD_FLAGS) -c -o $@

$(OBJDIR)/CarlaEng%.cpp.o: $(CWD)/backend/engine/CarlaEng%.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling CarlaEng$*.cpp (bridge)"
	$(SILENT)$(CXX) $< $(BUILD_CXX_FLAGS) $(NATIVE_BUILD_FLAGS) -c -o $@

# ---------------------------------------------------------------------------------------------------------------------
# arm32

$(OBJDIR)/CarlaBridgePlugin.cpp.arm32.o: CarlaBridgePlugin.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling $< (arm32 bridge)"
	$(SILENT)$(CXX) $< $(BUILD_CXX_FLAGS) $(ARM32_FLAGS) -c -o $@

$(OBJDIR)/CarlaStandalone.cpp.arm32.o: $(CWD)/backend/CarlaStandalone.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling CarlaStandalone.cpp (arm32 bridge)"
	$(SILENT)$(CXX) $< $(BUILD_CXX_FLAGS) $(ARM32_FLAGS) -c -o $@

$(OBJDIR)/CarlaEng%.cpp.arm32.o: $(CWD)/backend/engine/CarlaEng%.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling CarlaEng$*.cpp (arm32 bridge)"
	$(SILENT)$(CXX) $< $(BUILD_CXX_FLAGS) $(ARM32_FLAGS) -c -o $@

$(OBJDIR)/CarlaPlug%.cpp.arm32.o: $(CWD)/backend/plugin/CarlaPlug%.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling CarlaPlug$*.cpp (arm32 bridge)"
	$(SILENT)$(CXX) $< $(BUILD_CXX_FLAGS) $(ARM32_FLAGS) -c -o $@

# ----------------------------------------------------------------------------------------------------------------------
# posix32

ifeq ($(MACOS),true)
$(OBJDIR)/CarlaPluginVST2.cpp.posix32.o: $(CWD)/backend/plugin/CarlaPluginVST2.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling CarlaPluginVST2.cpp (posix32 bridge)"
	$(SILENT)$(CXX) $< $(BUILD_CXX_FLAGS) $(32BIT_FLAGS) -ObjC++ -c -o $@

$(OBJDIR)/CarlaPluginJuce.cpp.posix32.o: $(CWD)/backend/plugin/CarlaPluginJuce.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling CarlaPluginJuce.cpp (posix32 bridge)"
	$(SILENT)$(CXX) $< $(BUILD_CXX_FLAGS) $(32BIT_FLAGS) -ObjC++ -c -o $@

$(OBJDIR)/CarlaBridgePlugin.cpp.posix32.o: CarlaBridgePlugin.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling $< (posix32 bridge)"
	$(SILENT)$(CXX) $< $(BUILD_CXX_FLAGS) $(32BIT_FLAGS) -ObjC++ -c -o $@

$(OBJDIR)/CarlaStandalone.cpp.posix32.o: $(CWD)/backend/CarlaStandalone.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling CarlaStandalone.cpp (posix32 bridge)"
	$(SILENT)$(CXX) $< $(BUILD_CXX_FLAGS) $(32BIT_FLAGS) -ObjC++ -c -o $@
else
$(OBJDIR)/CarlaBridgePlugin.cpp.posix32.o: CarlaBridgePlugin.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling $< (posix32 bridge)"
	$(SILENT)$(CXX) $< $(BUILD_CXX_FLAGS) $(32BIT_FLAGS) -c -o $@

$(OBJDIR)/CarlaStandalone.cpp.posix32.o: $(CWD)/backend/CarlaStandalone.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling CarlaStandalone.cpp (posix32 bridge)"
	$(SILENT)$(CXX) $< $(BUILD_CXX_FLAGS) $(32BIT_FLAGS) -c -o $@
endif

$(OBJDIR)/CarlaEng%.cpp.posix32.o: $(CWD)/backend/engine/CarlaEng%.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling CarlaEng$*.cpp (posix32 bridge)"
	$(SILENT)$(CXX) $< $(BUILD_CXX_FLAGS) $(32BIT_FLAGS) -c -o $@

$(OBJDIR)/CarlaPlug%.cpp.posix32.o: $(CWD)/backend/plugin/CarlaPlug%.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling CarlaPlug$*.cpp (posix32 bridge)"
	$(SILENT)$(CXX) $< $(BUILD_CXX_FLAGS) $(32BIT_FLAGS) -c -o $@

# ---------------------------------------------------------------------------------------------------------------------
# posix64

ifeq ($(MACOS),true)
$(OBJDIR)/CarlaPluginVST2.cpp.posix64.o: $(CWD)/backend/plugin/CarlaPluginVST2.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling CarlaPluginVST2.cpp (posix64 bridge)"
	$(SILENT)$(CXX) $< $(BUILD_CXX_FLAGS) $(64BIT_FLAGS) -ObjC++ -c -o $@

$(OBJDIR)/CarlaPluginJuce.cpp.posix64.o: $(CWD)/backend/plugin/CarlaPluginJuce.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling CarlaPluginJuce.cpp (posix64 bridge)"
	$(SILENT)$(CXX) $< $(BUILD_CXX_FLAGS) $(64BIT_FLAGS) -ObjC++ -c -o $@

$(OBJDIR)/CarlaBridgePlugin.cpp.posix64.o: CarlaBridgePlugin.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling $< (posix64 bridge)"
	$(SILENT)$(CXX) $< $(BUILD_CXX_FLAGS) $(64BIT_FLAGS) -ObjC++ -c -o $@

$(OBJDIR)/CarlaStandalone.cpp.posix64.o: $(CWD)/backend/CarlaStandalone.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling CarlaStandalone.cpp (posix64 bridge)"
	$(SILENT)$(CXX) $< $(BUILD_CXX_FLAGS) $(64BIT_FLAGS) -ObjC++ -c -o $@
else
$(OBJDIR)/CarlaBridgePlugin.cpp.posix64.o: CarlaBridgePlugin.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling $< (posix64 bridge)"
	$(SILENT)$(CXX) $< $(BUILD_CXX_FLAGS) $(64BIT_FLAGS) -c -o $@

$(OBJDIR)/CarlaStandalone.cpp.posix64.o: $(CWD)/backend/CarlaStandalone.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling CarlaStandalone.cpp (posix64 bridge)"
	$(SILENT)$(CXX) $< $(BUILD_CXX_FLAGS) $(64BIT_FLAGS) -c -o $@
endif

$(OBJDIR)/CarlaEng%.cpp.posix64.o: $(CWD)/backend/engine/CarlaEng%.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling CarlaEng$*.cpp (posix64 bridge)"
	$(SILENT)$(CXX) $< $(BUILD_CXX_FLAGS) $(64BIT_FLAGS) -c -o $@

$(OBJDIR)/CarlaPlug%.cpp.posix64.o: $(CWD)/backend/plugin/CarlaPlug%.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling CarlaPlug$*.cpp (posix64 bridge)"
	$(SILENT)$(CXX) $< $(BUILD_CXX_FLAGS) $(64BIT_FLAGS) -c -o $@

# ---------------------------------------------------------------------------------------------------------------------
# win32

$(OBJDIR)/CarlaBridgePlugin.cpp.win32.o: CarlaBridgePlugin.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling $< (win32 bridge)"
	$(SILENT)$(CXX) $< $(BUILD_CXX_FLAGS) $(32BIT_FLAGS) -c -o $@

$(OBJDIR)/CarlaEng%.cpp.win32.o: $(CWD)/backend/engine/CarlaEng%.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling CarlaEng$*.cpp (win32 bridge)"
	$(SILENT)$(CXX) $< $(BUILD_CXX_FLAGS) $(32BIT_FLAGS) -c -o $@

$(OBJDIR)/CarlaPlug%.cpp.win32.o: $(CWD)/backend/plugin/CarlaPlug%.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling CarlaPlug$*.cpp (win32 bridge)"
	$(SILENT)$(CXX) $< $(BUILD_CXX_FLAGS) $(32BIT_FLAGS) -c -o $@

$(OBJDIR)/CarlaStandalone.cpp.win32.o: $(CWD)/backend/CarlaStandalone.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling CarlaStandalone.cpp (win32 bridge)"
	$(SILENT)$(CXX) $< $(BUILD_CXX_FLAGS) $(32BIT_FLAGS) -c -o $@

# ---------------------------------------------------------------------------------------------------------------------
# win64

$(OBJDIR)/CarlaBridgePlugin.cpp.win64.o: CarlaBridgePlugin.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling $< (win64 bridge)"
	$(SILENT)$(CXX) $< $(BUILD_CXX_FLAGS) $(64BIT_FLAGS) -c -o $@

$(OBJDIR)/CarlaEng%.cpp.win64.o: $(CWD)/backend/engine/CarlaEng%.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling CarlaEng$*.cpp (win64 bridge)"
	$(SILENT)$(CXX) $< $(BUILD_CXX_FLAGS) $(64BIT_FLAGS) -c -o $@

$(OBJDIR)/CarlaPlug%.cpp.win64.o: $(CWD)/backend/plugin/CarlaPlug%.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling CarlaPlug$*.cpp (win64 bridge)"
	$(SILENT)$(CXX) $< $(BUILD_CXX_FLAGS) $(64BIT_FLAGS) -c -o $@

$(OBJDIR)/CarlaStandalone.cpp.win64.o: $(CWD)/backend/CarlaStandalone.cpp
	-@mkdir -p $(OBJDIR)
	@echo "Compiling CarlaStandalone.cpp (win64 bridge)"
	$(SILENT)$(CXX) $< $(BUILD_CXX_FLAGS) $(64BIT_FLAGS) -c -o $@

# ---------------------------------------------------------------------------------------------------------------------

-include $(OBJS_lv2:%.o=%.d)
-include $(OBJS_arm32:%.o=%.d)
-include $(OBJS_posix32:%.o=%.d)
-include $(OBJS_posix64:%.o=%.d)
-include $(OBJS_win32:%.o=%.d)
-include $(OBJS_win64:%.o=%.d)

# ---------------------------------------------------------------------------------------------------------------------
