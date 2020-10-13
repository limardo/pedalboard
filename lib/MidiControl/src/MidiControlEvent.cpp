//
// Created by Luca Limardo on 12/10/2020.
//

#include <MidiControl.h>

void MidiControlEvent::emit(MidiControlEventType type, int data, int note) {
    switch (type) {
        case POWER:
            manager.power(data, note);
            break;
        case SHUTDOWN:
            manager.shutdown(data, note);
            break;
    }
}

void MidiControlEvent::on(MidiControlManager *pManager) {
    this->manager = *pManager;
}