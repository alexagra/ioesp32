#include "IOesp.h"
#include "Arduino.h"



Input::Input(int pin,int res)
{

	pinIn = pin;
	if(res == 8)
		pinMode(pinIn, INPUT_PULLDOWN);
	else if(res == 4)
		pinMode(pinIn, INPUT_PULLUP);

}

Output::Output(int pin)
{
	pinOut = pin;
	pinMode(pinOut, OUTPUT);
	
}
Pwm::Pwm(int pin,int channel)
{

	pinOut = pin;
	
	chan = channel;
	ledcSetup(chan, 5000, 8); 
	ledcAttachPin(pinOut, chan);

	
}



int Input::read()
{
	value = digitalRead(pinIn);
	return value;
}

int Input::readAN()
{
	value = analogRead(pinIn);
	return value;
}



void Output::on()
{

	digitalWrite(pinOut, HIGH);


}
void Output::off()
{
	digitalWrite(pinOut, LOW);
}

void Output::blink(int times, float delays)
{
	int delayms = delays * 1000;
	for (int i = 0; i < times; i++)
	{
		digitalWrite(pinOut, HIGH);
		delay(delayms);
		digitalWrite(pinOut, LOW);
		delay(delayms);

	}

}

int Output::read()
{
	return digitalRead(pinOut);
}
Output_n::Output_n(int pin)
{
	pinOut = pin;
	digitalWrite(pinOut, HIGH);
	pinMode(pinOut, OUTPUT);
}

void Output_n::on()
{
	digitalWrite(pinOut, LOW);

}

void Output_n::off()
{
	digitalWrite(pinOut, HIGH);

}

void Output_n::blink(int times, float delays)
{
	int delayms = delays * 1000;
	for (int i = 0; i < times; i++)
	{
		digitalWrite(pinOut, LOW);
		delay(delayms);
		digitalWrite(pinOut, HIGH);
		delay(delayms);

	}
}

int Output_n::read()
{
	return !digitalRead(pinOut);
}

void Pwm::onAN(int val)
{
	
	ledcWrite(chan, val);

}

void Pwm::smoothOn(float xr)
{
	xr = xr * 1000;

	for (int i = 0; i < 255; i++)
	{
		
		ledcWrite(chan, i);
		delay(xr / 255);
	}
}

void Pwm::smoothOff(float xr)
{
	xr = xr * 1000;
	for (int i = 254; i >= 0; i--)
	{
		
		ledcWrite(chan, i);
		delay(xr / 255);
	}

}

void Pwm::off()
{
	ledcWrite(chan, 0);
}

void Pwm::on()
{
	ledcWrite(chan, 255);

}


void wait(float x)
{
	delay(x * 1000);
}


