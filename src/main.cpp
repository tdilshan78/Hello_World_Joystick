#include "mbed.h"
#include "C12832_lcd.h" // Built-in library for the Application Board's LCD

C12832_LCD lcd;

// Initialize joystick pins (pull-down mode)
DigitalIn joystick_up(p15);
DigitalIn joystick_down(p12);
DigitalIn joystick_left(p13);
DigitalIn joystick_right(p16);
DigitalIn joystick_center(p14);

int main() {
    lcd.cls();
    lcd.locate(0, 0);
    lcd.printf("Hello World!");

    while (1) {
        if (joystick_up) {
            lcd.locate(0, 10);
            lcd.printf("UP    ");
        } else if (joystick_down) {
            lcd.locate(0, 10);
            lcd.printf("DOWN  ");
        } else if (joystick_left) {
            lcd.locate(0, 10);
            lcd.printf("LEFT  ");
        } else if (joystick_right) {
            lcd.locate(0, 10);
            lcd.printf("RIGHT ");
        } else if (joystick_center) {
            lcd.locate(0, 10);
            lcd.printf("CENTER");
        }

        ThisThread::sleep_for(100ms);
    }
}