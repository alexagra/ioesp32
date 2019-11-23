#include <IOesp.h>

Input button(13);    //pin
Output led1(2);
Pwm led2(4,1);      //pin,channel


void setup() 
{
  // put your setup code here, to run once:

}

void loop() 
{
  // put your main code here, to run repeatedly:

  int buttonStatus = button.read(); 
  int buttonStatus2 = button.readAN(); //read analog 0-1023
  led1.on();
  led1.off();
  led1.blink(4,0.5);  //times to blink,seconds

  led2.onAN(125); //analogWrite 0-254
  led2.smoothOn(4);
  led2.smoothOff(2); //seconds
 

}
