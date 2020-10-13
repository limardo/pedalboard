//
// Created by Luca Limardo on 17/10/2020.
//

#include <MidiControl.h>

void MidiControlSwitchNote::play() {
    usbMIDI.sendNoteOn(_note, 127, MIDI_CONTROL_CHANNEL);
}

void MidiControlSwitchNote::stop() {
    usbMIDI.sendNoteOff(_note, 0, MIDI_CONTROL_CHANNEL);
}

MidiControlSwitchNote::MidiControlSwitchNote(int button, int led, int note) :
        MidiControlButton(button, led, note) {
}

void MidiControlSwitchCC::play() {
    usbMIDI.sendControlChange(_note, 127, MIDI_CONTROL_CHANNEL);
}

void MidiControlSwitchCC::stop() {}

MidiControlSwitchCC::MidiControlSwitchCC(int button, int led, int note) :
        MidiControlButton(button, led, note) {
}
