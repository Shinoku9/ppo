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
    
    MyLcd.SetTextColor(LCD_COLOR_YELLOW);
    MyLcd.FillRect(ucLedPosition, ucLedIndex*80, 80, 80);
    
    MyLcd.SetTextColor(LCD_COLOR_GREEN);
    for(int a=0; a<4; a++){
        MyLcd.DrawRect(ucLedPosition, a*80, 80, 80);
    }

    MyLcd.SetFont(&Font24);

    MyLcd.SetBackColor(LCD_COLOR_RED);
    MyLcd.SetTextColor(LCD_COLOR_WHITE);
    MyLcd.DisplayStringAt(ucLedPosition, 0, (uint8_t *)"0", LEFT_MODE);
    MyLcd.DisplayStringAt(ucLedPosition, 80, (uint8_t *)"1", LEFT_MODE);
    MyLcd.DisplayStringAt(ucLedPosition, 160, (uint8_t *)"2", LEFT_MODE);
    MyLcd.DisplayStringAt(ucLedPosition, 240, (uint8_t *)"3", LEFT_MODE);
}
