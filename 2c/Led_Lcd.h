#ifndef LED_LCD_H
#define LED_LCD_H

class LedLcd{
    public:
        LedLcd(unsigned char ucLedX = 0);
        void On (unsigned char ucLedIndex);
    private:
        unsigned char ucLedPosition;
};

#endif
