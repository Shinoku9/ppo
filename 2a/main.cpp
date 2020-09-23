#include "mbed.h"
#include "TS_DISCO_F429ZI.h"
#include "LCD_DISCO_F429ZI.h"

LCD_DISCO_F429ZI MyLcd;
TS_DISCO_F429ZI MyTS;

int main(){
    TS_StateTypeDef TS_State;
    
    MyLcd.Clear(LCD_COLOR_BLACK);

    while(1){
        for(int a=0; a<4; a++){
            //niebieskie przyciski
            MyLcd.SetTextColor(LCD_COLOR_BLUE);
            MyLcd.FillRect(0, a*80, 80, 80);
        }
        
        MyTS.GetState(&TS_State);
        if ((TS_State.TouchDetected) && (TS_State.X > 0) && (TS_State.X < 80) && (TS_State.Y > 0) && (TS_State.Y < 80)){
            MyLcd.SetTextColor(LCD_COLOR_YELLOW);
            MyLcd.FillRect(0, 0, 80, 80);
        }
        else if ((TS_State.TouchDetected) && (TS_State.X > 0) && (TS_State.X < 80) && (TS_State.Y > 80) && (TS_State.Y < 160)){
            MyLcd.SetTextColor(LCD_COLOR_YELLOW);
            MyLcd.FillRect(0, 80, 80, 80);
        }
        else if ((TS_State.TouchDetected) && (TS_State.X > 0) && (TS_State.X < 80) && (TS_State.Y > 160) && (TS_State.Y < 240)){
            MyLcd.SetTextColor(LCD_COLOR_YELLOW);
            MyLcd.FillRect(0, 160, 80, 80);
        }
        else if ((TS_State.TouchDetected) && (TS_State.X > 0) && (TS_State.X < 80) && (TS_State.Y > 240) && (TS_State.Y < 320)){
            MyLcd.SetTextColor(LCD_COLOR_YELLOW);
            MyLcd.FillRect(0, 240, 80, 80);
        }
        
        for(int b=0; b<4; b++){
            //zielone ramki
            MyLcd.SetTextColor(LCD_COLOR_GREEN);
            MyLcd.DrawRect(0, b*80, 80, 80);
        }
        
        MyLcd.SetFont(&Font24);
        
        //czerwone
        MyLcd.SetBackColor(LCD_COLOR_RED);
        MyLcd.SetTextColor(LCD_COLOR_WHITE);
        MyLcd.DisplayStringAt(0, 0, (uint8_t *)"0", LEFT_MODE);
        MyLcd.DisplayStringAt(0, 80, (uint8_t *)"1", LEFT_MODE);
        MyLcd.DisplayStringAt(0, 160, (uint8_t *)"2", LEFT_MODE);
        MyLcd.DisplayStringAt(0, 240, (uint8_t *)"3", LEFT_MODE);
        
        wait(0.1);
    }
}
