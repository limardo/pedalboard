//
// Created by Luca Limardo on 13/10/2020.
//

#include <MidiControl.h>

MidiControlMomentary::MidiControlMomentary(int button, int led, int note) : MidiControlButton(button, led, note) {
    _id = 0;
    _button = button;
    _led = led;
    _note = note;

    _state = LOW;

    _instance = Button();
}

void MidiControlMomentary::update() {
    _instance.update();

    if (_instance.pressed()) {
        on();
    }

    if (_instance.released()) {
        off();
    }
}

void MidiControlMomentary::stop() {
    MidiControlButton::stop();
}

void MidiControlMomentary::play() {
    MidiControlButton::play();
}

MidiControlMomentaryNote::MidiControlMomentaryNote(int button, int led, int note) :
        MidiControlMomentary(button, led, note) {
}

void MidiControlMomentaryNote::play() {
    usbMIDI.sendNoteOn(_note, 127, MIDI_CONTROL_CHANNEL);
}

void MidiControlMomentaryNote::stop() {
    usbMIDI.sendNoteOff(_note, 0, MIDI_CONTROL_CHANNEL);
}

MidiControlMomentaryCC::MidiControlMomentaryCC(int button, int led, int note) :
        MidiControlMomentary(button, led, note) {
}

void MidiControlMomentaryCC::play() {
    usbMIDI.sendControlChange(_note, 127, MIDI_CONTROL_CHANNEL);
}

void MidiControlMomentaryCC::stop() {
}

MidiControlMomentaryKey::MidiControlMomentaryKey(int button, int led, int note) :
        MidiControlMomentary(button, led, note) {
}

void MidiControlMomentaryKey::play() {
    // Keyboard.press(_note);
}

void MidiControlMomentaryKey::stop() {
    // Keyboard.release(_note);
}
