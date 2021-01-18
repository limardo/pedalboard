//
// Created by Luca Limardo on 17/10/2020.
//

#ifndef PEDALBOARD_MIDIPRESETS_H
#define PEDALBOARD_MIDIPRESETS_H

#include <MidiButtons.h>
#include <MidiControl.h>

class MidiPresets {
public:
    virtual void startup();

    virtual void setup();

    virtual void loop();
};

class PresetKeyboard : public MidiPresets {
private:
    MidiControlMomentaryKey control1;
    MidiControlMomentaryKey control2;
    MidiControlMomentaryKey control3;
    MidiControlMomentaryKey control4;
    MidiControlMomentaryKey control5;

    MidiControlMomentaryKey control6;
    MidiControlMomentaryKey control7;
    MidiControlMomentaryKey control8;
    MidiControlMomentaryKey control9;
    MidiControlMomentaryKey control10;
public:
    PresetKeyboard();

    void startup() override;

    void setup() override;

    void loop() override;
};

class PresetCustom1 : public MidiPresets {
private:
    MidiControlMomentaryCC control1;
    MidiControlMomentaryCC control2;
    MidiControlMomentaryCC control3;
    MidiControlMomentaryCC control4;
    MidiControlMomentaryCC control5;

    MidiControlSwitchNote control6;
    MidiControlSwitchNote control7;
    MidiControlSwitchNote control8;
    MidiControlSwitchNote control9;
    MidiControlSwitchNote control10;

    MidiControlManager manager;
public:
    PresetCustom1();

    void startup() override;

    void setup() override;

    void loop() override;
};

class PresetRigKontrol : public MidiPresets {
private:
    MidiControlMomentaryCC control1;
    MidiControlMomentaryCC control2;
    MidiControlMomentaryCC control3;
    MidiControlMomentaryCC control4;
    MidiControlMomentaryCC control5;

    MidiControlSwitchCC control6;
    MidiControlSwitchCC control7;
    MidiControlSwitchCC control8;
    MidiControlSwitchCC control9;
    MidiControlSwitchCC control10;
public:
    PresetRigKontrol();

    void startup() override;

    void setup() override;

    void loop() override;
};

class PresetRocksmith : public MidiPresets {
private:
    MidiControlMomentaryKey control1;
    MidiControlMomentaryKey control2;
    MidiControlMomentaryKey control3;
    MidiControlMomentaryKey control4;
    MidiControlMomentaryKey control5;

    MidiControlMomentaryKey control6;
    MidiControlMomentaryKey control7;
    MidiControlMomentaryKey control8;
    MidiControlMomentaryKey control9;
    MidiControlMomentaryKey control10;
public:
    PresetRocksmith();

    void startup() override;

    void setup() override;

    void loop() override;
};

class PresetManager : public MidiPresets {
public:
    PresetKeyboard keyboard;

    PresetCustom1 custom1;

    PresetRigKontrol rigKontrol;

    PresetRocksmith rocksmith;
};

#endif //PEDALBOARD_MIDIPRESETS_H
