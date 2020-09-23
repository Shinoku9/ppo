#include "Led_Lcd.h"
#include "LCD_DISCO_F429ZI.h"

LCD_DISCO_F429ZI MyLcd;

LedLcd::LedLcd(unsigned char ucLedX){
    MyLcd.Clear(LCD_COLOR_BLACK);
    ucLedPosition = ucLedX*80;
}

void LedLcd::On(unsigned char ucLedIndex){
    MyLcd.SetTextColor(LCD_COLOR_BLUE);
    MyLcd.FillRect(ucLedPosition, 0, 80, 320);
    
    MyLcd.SetTextColor(LCD_COLOR_MAGENTA);
    MyLcd.FillRect(ucLedPosition, ucLedIndex*80, 80, 80);
    
    MyLcd.SetFont(&Font24);
    MyLcd.SetBackColor(LCD_COLOR_RED);
    unsigned char ucButtonNumber[1];
    for(ucLedIndex=0; ucLedIndex<4; ucLedIndex++){
        MyLcd.SetTextColor(LCD_COLOR_WHITE);
        sprintf((char *)ucButtonNumber, "%d", ucLedIndex);
        MyLcd.DisplayStringAt(ucLedPosition, ucLedIndex*80, (uint8_t *) ucButtonNumber, LEFT_MODE);
        MyLcd.SetTextColor(LCD_COLOR_GREEN);
        MyLcd.DrawRect(ucLedPosition, ucLedIndex*80, 80, 80);
    }
}
