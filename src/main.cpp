#include <MidiPresets.h>

PresetManager presets;

void setup() {
    presets.rocksmith.setup();
}

void loop() {
    presets.rocksmith.loop();
}