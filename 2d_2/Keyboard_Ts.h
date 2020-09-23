#ifndef KEYBOARD_TS_H
#define KEYBOARD_TS_H

enum KeyboardState{
    RELEASED,
    BUTTON_0,
    BUTTON_1,
    BUTTON_2,
    BUTTON_3
};

class KeyboardTs{
    public:
        enum KeyboardState eRead();
        KeyboardTs(unsigned char ucKeyboardX = 0);
    private:
        unsigned char ucKeyboardPosition;
};

#endif
