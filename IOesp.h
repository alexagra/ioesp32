

#ifndef IOesp_h
#define IOesp_h


#include "Arduino.h"



void wait(float);

class Input   //all pins except 34-39 are pulldown ,for pull up use - pinMode(pin,INPUT_PULLUP)- to setup
{

private:
	int pinIn; 
	int value;

public:
	Input( int); 
	int read();
	int readAN();

};
class Output
{

private:
	int pinOut;
	

	

public:
	Output( int);
	void on();
	void off();
	void blink(int, float);
	
	

};
class Output_n
{
private:
	int pinOut;


public:
	Output_n(int);
	void on();
	void off();
	void blink(int, float);
};

class Pwm
{
public:
	Pwm( int, int);
	void onAN(int);
	void smoothOn(float);
	void smoothOff(float);
	void off();
	void on();


private:
	int pinOut;
	int chan;
	
};



#endif
