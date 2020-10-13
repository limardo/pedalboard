#include <MidiPresets.h>

PresetKeyboard::PresetKeyboard() :
        control1(BUTTON_1, LED_1, 0),
        control2(BUTTON_2, LED_2, 0),
        control3(BUTTON_3, LED_3, 0),
        control4(BUTTON_4, LED_4, 0),
        control5(BUTTON_5, LED_5, 0),
        control6(BUTTON_6, LED_6, 0),
        control7(BUTTON_7, LED_7, KEY_T),
        control8(BUTTON_8, LED_8, KEY_P),
        control9(BUTTON_9, LED_9, KEY_SPACE),
        control10(BUTTON_10, LED_10, KEY_R) {
}

void PresetKeyboard::startup() {
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

void PresetKeyboard::setup() {
    Serial.begin(9600);

    control1.init();
    control2.init();
    control3.init();
    control4.init();
    control5.init();
    control6.init();
    control7.init();
    control8.init();
    control9.init();
    control10.init();

    startup();
}

void PresetKeyboard::loop() {
    control1.update();
    control2.update();
    control3.update();
    control4.update();
    control5.update();
    control6.update();
    control7.update();
    control8.update();
    control9.update();
    control10.update();
}