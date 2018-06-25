#ifndef DRONEBOX
#define DRONEBOX


#include <Arduino.h>
#include <SLIPEncodedSerial.h>
#include <OSCBundle.h>

#define TOUCH1_1 A5
#define TOUCH1_2 A4
#define TOUCH1_3 A3
#define TOUCH1_4 A2

#define TOUCH2_1 A9
#define TOUCH2_2 A8
#define TOUCH2_3 A7
#define TOUCH2_4 A6

#define TOUCH3_1 A17
#define TOUCH3_2 A16
#define TOUCH3_3 A15
#define TOUCH3_4 A14





#define USE_OSC

/*--------------------------ARM CPU reset Macro-------------------------*/

#define CPU_RESTART_ADDR (uint32_t *)0xE000ED0C
#define CPU_RESTART_VAL 0x5FA0004
#define CPU_RESTART (*CPU_RESTART_ADDR = CPU_RESTART_VAL)


/*------------------------------SHIFTPWM SETUP----------------------------*/

#define SHIFTPWM_FREQUENCY 275
#define SHIFTPWM_NUM_REGISTERS 7
#define SHIFTPWM_MAX_BRIGHTNESS 255

#define SHIFTPWM_LATCHPIN 10
#define SHIFTPWM_DATAPIN 11
#define SHIFTPWM_CLOCKPIN 13

extern const int ShiftPWM_latchPin;
extern const int ShiftPWM_dataPin;
extern const int ShiftPWM_clockPin;

extern const bool ShiftPWM_balanceLoad;
extern const bool ShiftPWM_invertOutputs;

extern int freq;
extern int spray;
extern int pitch;
extern int vol;



extern const int numPins;

void setf(OSCMessage&);
void setspray(OSCMessage&);
void setpitch(OSCMessage&);
void setvol(OSCMessage&);

class DroneBox
{
  
  public:
    bool init(void);
    void setupShiftPWM(void);
    void setAll(uint8_t _brightness);
    void setOne(int _pin, uint8_t _brightness);
    void setOne(int _x, int _y, int _z,  char _brightness_red, char _brightness_blue);
    void setOneBlue(int _x, int _y, int _z,  char _brightness);
    void setOneRed(int _x, int _y, int _z,  char _brightness);
    void fadeOut(void);
    void animate(char type, uint8_t speed);
    void render(void);
    void processUART(void);
    void processOutput(void);
    void setTouchY(void);
    void setTouchX(void);
    void readTouchX(void);
    void readTouchY(void);
  private:

    char _loading_cursor;
    

};


void itoc(int _i, char * _char);

#include "DroneBoxAnimation.h"


#endif
