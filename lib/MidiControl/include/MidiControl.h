//
// Created by Luca Limardo on 12/10/2020.
//

#ifndef PEDALBOARD_MIDICONTROL_H
#define PEDALBOARD_MIDICONTROL_H

#include <Arduino.h>
#include <Bounce2.h>

#define MIDI_CONTROL_BUTTON_INTERVAL 25
#define MIDI_CONTROL_CHANNEL 1

class MidiControlButton;

enum MidiControlEventType : int {
    POWER = 0,
    SHUTDOWN = 1
};

class MidiControlManager {
private:
    MidiControlButton **controls = 0;
    int controlCount;

public:
    MidiControlManager();

    void init();

    void add(MidiControlButton *control);

    void remove(MidiControlButton *control);

    void reset(int index);

    void update();

    void power(int data, int note);

    void shutdown(int data, int note);
};

class MidiControlEvent {
private:
    MidiControlManager manager;

public:
    void emit(MidiControlEventType type, int data, int note);

    void on(MidiControlManager *pManager);
};

class MidiControlButton {
protected:
    int _id;
    int _state;
    int _button;
    int _led;
    int _note;
    Button _instance;

    void emit(int event);

public:
    MidiControlButton(int button, int led, int note);

    MidiControlEvent power;
    MidiControlEvent shutdown;

    void init();

    bool isActive() const;

    void setId(int id);

    int getId() const;

    void toggle();

    void on();

    void off();

    void ledStart();

    void ledInit();

    virtual void play();

    virtual void stop();

    virtual void update();
};

class MidiControlMomentary : public MidiControlButton {
public:
    MidiControlMomentary(int button, int led, int note);

    void play() override;

    void stop() override;

    void update() override;
};

class MidiControlMomentaryNote : public MidiControlMomentary {
public:
    MidiControlMomentaryNote(int button, int led, int note);

    void play() override;

    void stop() override;
};

class MidiControlMomentaryCC : public MidiControlMomentary {
public:
    MidiControlMomentaryCC(int button, int led, int note);

    void play() override;

    void stop() override;
};

class MidiControlMomentaryKey : public MidiControlMomentary {
public:
    MidiControlMomentaryKey(int button, int led, int note);

    void play() override;

    void stop() override;
};

class MidiControlSwitchNote : public MidiControlButton {
public:
    MidiControlSwitchNote(int button, int led, int note);

    void play() override;

    void stop() override;
};

class MidiControlSwitchCC : public MidiControlButton {
public:
    MidiControlSwitchCC(int button, int led, int note);

    void play() override;

    void stop() override;
};

#endif //PEDALBOARD_MIDICONTROL_H
