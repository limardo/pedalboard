//
// Created by Luca Limardo on 12/10/2020.
//

#include <MidiControl.h>

MidiControlManager::MidiControlManager() {
    delete controls;

    controls = new MidiControlButton *[24];
    controlCount = 0;
}

void MidiControlManager::init() {
    for (int i = 0; i < controlCount; i++) {
        controls[i]->init();
        controls[i]->setId(i);
        controls[i]->power.on(this);
        controls[i]->shutdown.on(this);
    }
}

void MidiControlManager::power(int id, int note) {
    Serial.println(id);
    reset(id);
}

void MidiControlManager::shutdown(int id, int note) {
}

void MidiControlManager::add(MidiControlButton *control) {
    controls[controlCount] = control;
    controlCount++;
}

void MidiControlManager::remove(MidiControlButton *control) {
    for (int i = 0; i < controlCount; i++) {
        if (controls[i] == control) {
            controls[i] = nullptr;
        }
    }
}

void MidiControlManager::reset(int index) {
    for (int i = 0; i < controlCount; i++) {
        if (i != index) {
            controls[i]->off();
        }
    }
}

void MidiControlManager::update() {
    for (int i = 0; i < controlCount; i++) {
        controls[i]->update();
    }
}