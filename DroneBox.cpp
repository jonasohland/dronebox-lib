#include "DroneBox.h"

#define SHIFTPWM_NOSPI

#define FADETIME 3

const bool ShiftPWM_invertOutputs = false;
const bool ShiftPWM_balanceLoad = false;

const int ShiftPWM_latchPin = SHIFTPWM_LATCHPIN;
const int ShiftPWM_dataPin = SHIFTPWM_DATAPIN;
const int ShiftPWM_clockPin = SHIFTPWM_CLOCKPIN;

int freq;
int spray;
int pitch;
int vol;

char fademem[250];

#include <ShiftPWM.h>

SLIPEncodedSerial SLIPSerial = SLIPEncodedSerial(Serial1);



/*---------------------init and setup--------------------*/

bool DroneBox::init(){
	this->setupShiftPWM();
	SLIPSerial.begin(500000);

	return true;

}


void DroneBox::setupShiftPWM()
{
	ShiftPWM.SetAmountOfRegisters(SHIFTPWM_NUM_REGISTERS);
	ShiftPWM.Start(SHIFTPWM_FREQUENCY, SHIFTPWM_MAX_BRIGHTNESS);

}


void DroneBox::setAll(uint8_t _brightness)
{
	for (int i = 0; i < ShiftPWM.m_amountOfOutputs; i++)
	{
		ShiftPWM.m_PWMValues[i] = _brightness;
	}
}
void DroneBox::setOne(int _pin, uint8_t _brightness)
{
	ShiftPWM.m_PWMValues[_pin] = _brightness;
	
}

void DroneBox::fadeOut(){

	for(int i = 0; i < 250; i++){

			if(fademem[i] > 0){

				int _new  = fademem[i] - FADETIME;

				if(_new > 0){
					fademem[i] = _new;
				}
				else{
					fademem[i] = 0;
				}

				ShiftPWM.m_PWMValues[i] = fademem[i];
				//Serial.print((int)_new);
				//Serial.print("  ");
			} 
			
		}
	

}





void DroneBox::setOne(int _x, int _y, int _z,  char _brightness_red, char _brightness_blue)
{
	
	int _redOutput = _x * 2 + _y * 10 + _z * 50;
	int _blueOutput = 1 + _x * 2 + _y * 10 + _z * 50;

	ShiftPWM.m_PWMValues[_redOutput] = _brightness_red;
	ShiftPWM.m_PWMValues[_blueOutput] = _brightness_blue;

	fademem[_redOutput] = _brightness_red;
	fademem[_blueOutput] = _brightness_blue;

}

void DroneBox::setOneRed(int _x, int _y, int _z,  char _brightness)
{
	
	ShiftPWM.m_PWMValues[_x * 2 + _y * 10 + _z * 50] = _brightness;
	
}

void DroneBox::setOneBlue(int _x, int _y, int _z,  char _brightness)
{
	
	
	ShiftPWM.m_PWMValues[1 + _x * 2 + _y * 10 + _z * 50] = _brightness;
}

void DroneBox::setTouchX(){
	
  	pinMode(TOUCH1_1, INPUT);   // A0
	pinMode(TOUCH2_1, INPUT);   // A0
	pinMode(TOUCH3_1, INPUT);   // A0
	


  	pinMode(TOUCH1_2, OUTPUT);    // A1
	pinMode(TOUCH2_2, OUTPUT);    // A1
	pinMode(TOUCH3_2, OUTPUT);    // A1
	


  	pinMode(TOUCH1_3, INPUT);   // A2
	pinMode(TOUCH2_3, INPUT);   // A2
	pinMode(TOUCH3_3, INPUT);   // A2
	

	pinMode(TOUCH1_4, OUTPUT);   // A3
	pinMode(TOUCH2_4, OUTPUT);   // A3
	pinMode(TOUCH3_4, OUTPUT);   // A3
	

	digitalWriteFast(TOUCH1_2, LOW);    
	digitalWriteFast(TOUCH2_2, LOW);    
	digitalWriteFast(TOUCH3_2, LOW);    
	   

	digitalWriteFast(TOUCH1_4, HIGH);   
	digitalWriteFast(TOUCH2_4, HIGH);    
	digitalWriteFast(TOUCH3_4, HIGH);    
	   




}
void DroneBox::setTouchY(){

  	pinMode(TOUCH1_1, OUTPUT);   // A0
	pinMode(TOUCH2_1, OUTPUT);   // A0
	pinMode(TOUCH3_1, OUTPUT);   // A0
	


  	pinMode(TOUCH1_2, INPUT);    // A1
	pinMode(TOUCH2_2, INPUT);    // A1
	pinMode(TOUCH3_2, INPUT);    // A1
	


  	pinMode(TOUCH1_3, OUTPUT);   // A2
	pinMode(TOUCH2_3, OUTPUT);   // A2
	pinMode(TOUCH3_3, OUTPUT);   // A2
	

	pinMode(TOUCH1_4, INPUT);   // A3
	pinMode(TOUCH2_4, INPUT);   // A3
	pinMode(TOUCH3_4, INPUT);   // A3
	

	digitalWriteFast(TOUCH1_1, LOW);    
	digitalWriteFast(TOUCH2_1, LOW);    
	digitalWriteFast(TOUCH3_1, LOW);    
	   

	digitalWriteFast(TOUCH1_3, HIGH);   
	digitalWriteFast(TOUCH2_3, HIGH);    
	digitalWriteFast(TOUCH3_3, HIGH);    
	  
	
}
void DroneBox::readTouchX(){
	
	bool send = 0;
	int xr1 = analogRead(TOUCH1_1); 
	int xr2 = analogRead(TOUCH2_1);
	int xr3 = analogRead(TOUCH3_1);
	
	OSCBundle bndl = OSCBundle();
	if(xr1 < 800 && xr1  > 2){
		
		bndl.add("/x1").add((int32_t)xr1);
		send = 1;
			
		
	}
	if(xr2 < 800 && xr2> 2){
		
		bndl.add("/x2").add((int32_t)xr2);
		send = 1;
			
		
	}
	if(xr3 < 800 && xr3> 2){

		bndl.add("/x3").add((int32_t)xr3);
		send = 1;
		
		
	}

	if(send){
		SLIPSerial.beginPacket();
			bndl.send(SLIPSerial);
		SLIPSerial.endPacket();
		bndl.empty();
	}
	

}

void DroneBox::readTouchY(){
	bool send = 0;
	int yr1=analogRead(TOUCH1_4);
	int yr2=analogRead(TOUCH2_4);
	int yr3=analogRead(TOUCH3_4);
	
	OSCBundle bndl = OSCBundle();
	if(yr1 < 800 && yr1 > 2){
	
		bndl.add("/y1").add((int32_t)yr1);
		send = 1;
		
	}
	if(yr2 < 800 && yr2 > 2){
	
		bndl.add("/y2").add((int32_t)yr2);
		send = 1;
		
	
	}
	if(yr3 < 800 && yr3 > 2){
	
		bndl.add("/y3").add((int32_t)yr3);
		send = 1;
		
	}

	if(send){

		SLIPSerial.beginPacket();
		bndl.send(SLIPSerial);
		SLIPSerial.endPacket();
		bndl.empty();

	}
	
		
	

}

void DroneBox::render()
{
	


}

void DroneBox::processUART(){
OSCBundle bundleIN;

  	int size;

  if(SLIPSerial.available()){
   	while(!SLIPSerial.endofPacket()){
		if( (size =SLIPSerial.available()) > 0)
		{
		while(size--)
			bundleIN.fill(SLIPSerial.read());
		}
		bundleIN.dispatch("/f", setf);
		bundleIN.dispatch("/s", setspray);
		bundleIN.dispatch("/p", setpitch);
		bundleIN.dispatch("/v", setvol);
		

	
	}
	
  }
  bundleIN.empty();
   //bundleIN.dispatch("/f", setf);
}

void setf(OSCMessage &msg){
	freq = (char)msg.getInt(0);


}
void setspray(OSCMessage &msg){
	
	spray = (char)msg.getInt(0);

}
void setpitch(OSCMessage &msg){
	
	pitch = (char)msg.getInt(0);

}
void setvol(OSCMessage &msg){
	
	vol = (char)msg.getInt(0);

}



void DroneBox::processOutput(){
	

}
	    

