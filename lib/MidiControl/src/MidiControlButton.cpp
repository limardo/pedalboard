//
// Created by Luca Limardo on 12/10/2020.
//

#include <MidiControl.h>

MidiControlButton::MidiControlButton(int button, int led, int note) {
    // _id = 0;
    _button = button;
    _led = led;
    _note = note;

    _state = LOW;

    _instance = Button();
}

void MidiControlButton::init() {
    _instance.attach(_button, INPUT_PULLUP);
    _instance.interval(MIDI_CONTROL_BUTTON_INTERVAL);
    _instance.setPressedState(_state);

    pinMode(_led, OUTPUT);

    digitalWrite(_led, _state);
}

bool MidiControlButton::isActive() const {
    return _state == LOW;
}

void MidiControlButton::setId(int id) {
    _id = id;
}

int MidiControlButton::getId() const {
    return _id;
}

void MidiControlButton::toggle() {
    _state == HIGH ? off() : on();
}

void MidiControlButton::on() {
    _state = HIGH;

    digitalWrite(_led, _state);

    play();

    power.emit(MidiControlEventType::POWER, _id, _note);
}

void MidiControlButton::off() {
    _state = LOW;

    digitalWrite(_led, _state);

    stop();

    shutdown.emit(MidiControlEventType::SHUTDOWN, _id, _note);
}

void MidiControlButton::ledStart() {
    digitalWrite(_led, HIGH);
}

void MidiControlButton::ledInit() {
    digitalWrite(_led, _state);
}

void MidiControlButton::play() {
}

void MidiControlButton::stop() {
}

void MidiControlButton::update() {
    _instance.update();

    if (_instance.pressed()) {
        emit(_state == HIGH ? LOW : HIGH);
    }
}

void MidiControlButton::emit(int event) {
    if (_state != event) {
        toggle();
    }
}

