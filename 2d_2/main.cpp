#include "mbed.h"
#include "KeyboardTsLcd.h"
#include "Led_Lcd.h"

int main(){
    KeyboardTsLcd Keyboard(0);
    LedLcd Led(2);
    
    while(1){
        enum KeyboardState eBtn = Keyboard.eRead();
        switch(eBtn){
            case BUTTON_0:
                Led.On(3);
                break;
            case BUTTON_1:
                Led.On(2);
                break;
            case BUTTON_2:
                Led.On(1);
                break;
            case BUTTON_3:
                Led.On(0);
                break;
            default:
                Led.On(4);
                break;
        }
        wait(0.1);
    }
}

