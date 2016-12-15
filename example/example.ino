/*
 Name:    LS7366R.ino
 Created: 5/16/2016 4:15:49 PM
 Author:  anil adiguzel
 Editor:  http://www.visualmicro.com
*/

#include <SPI.h>
#include "LS7366RLib.h"
# define SSS 53
LS7366R Encoder1(SSS);

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  Encoder1.ResetEncoder();
}

// the loop function runs over and over again until power down or reset
void loop() {
  int32_t EncoderValue1 = Encoder1.ReadEncoder();
  Serial.println(EncoderValue1);
}
