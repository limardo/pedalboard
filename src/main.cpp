#include <MidiPresets.h>

PresetManager presets;

void setup() {
    presets.keyboard.setup();
}

void loop() {
    presets.keyboard.loop();
}