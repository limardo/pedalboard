#include <MidiPresets.h>

PresetCustom1::PresetCustom1() :
        control1(BUTTON_1, LED_1, 76),
        control2(BUTTON_2, LED_2, 77),
        control3(BUTTON_3, LED_3, 78),
        control4(BUTTON_4, LED_4, 79),
        control5(BUTTON_5, LED_5, 80),
        control6(BUTTON_6, LED_6, 81),
        control7(BUTTON_7, LED_7, 82),
        control8(BUTTON_8, LED_8, 83),
        control9(BUTTON_9, LED_9, 84),
        control10(BUTTON_10, LED_10, 85) {
}

void PresetCustom1::startup() {
    control1.ledStart();
    control2.ledStart();
    control3.ledStart();
    control4.ledStart();
    control5.ledStart();
    control6.ledStart();
    control7.ledStart();
    control8.ledStart();
    control9.ledStart();
    control10.ledStart();

    delay(2000);

    control1.ledInit();
    control2.ledInit();
    control3.ledInit();
    control4.ledInit();
    control5.ledInit();
    control6.ledInit();
    control7.ledInit();
    control8.ledInit();
    control9.ledInit();
    control10.ledInit();
}

void PresetCustom1::setup() {
    Serial.begin(9600);

    manager.add(&control6);
    manager.add(&control7);
    manager.add(&control8);
    manager.add(&control9);
    manager.add(&control10);

    control1.init();
    control2.init();
    control3.init();
    control4.init();
    control5.init();

    manager.init();

    startup();
}

void PresetCustom1::loop() {
    control1.update();
    control2.update();
    control3.update();
    control4.update();
    control5.update();

    manager.update();
}