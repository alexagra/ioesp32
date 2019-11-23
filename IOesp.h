

#ifndef IOesp_h
#define IOesp_h


#include "Arduino.h"



void wait(float);

class Input
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
	void onNL();
	void offNL();
	

};

class Pwm
{
public:
	Pwm( int, int);
	void onAN(int);
	void smoothOn(float);
	void smoothOff(float);


private:
	int pinOut;
	int chan;
	
};



#endif
