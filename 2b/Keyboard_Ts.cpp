#include "Keyboard_Ts.h"
#include "TS_DISCO_F429ZI.h"

TS_DISCO_F429ZI MyTS;
TS_StateTypeDef TS_State;

enum KeyboardState KeyboardTs::eRead(){
    MyTS.GetState(&TS_State);
    if(TS_State.TouchDetected){
        if((TS_State.X > 0) && (TS_State.X <80)){
            if((TS_State.Y > 0) && (TS_State.Y < 80)){
                return BUTTON_0;
            }
            else if((TS_State.Y > 80) && (TS_State.Y < 160)){
                return BUTTON_1;
            }
            else if ((TS_State.Y > 160) && (TS_State.Y < 240)){
                return BUTTON_2;
            }
            else if ((TS_State.Y > 240) && (TS_State.Y < 320)){
                return BUTTON_3;
            }
        }
    }
    return RELEASED;
}
