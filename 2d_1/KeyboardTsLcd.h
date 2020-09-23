#ifndef KEYBOARDTSLCD_H
#define KEYBOARDTSLCD_H

#include "Keyboard_Ts.h"
#include "Led_Lcd.h"

class KeyboardTsLcd{
    public:
        KeyboardTsLcd(unsigned char);
        enum KeyboardState eRead();
    private:
        KeyboardTs *pKeyboard;
        LedLcd *pLed;
};

#endif
