#include "FlexLibrary.h"

Flex flex1(A0); 
Flex flex2(A1);
Flex flex3(A2);
Flex flex4(A3);
Flex flex5(A6);

void setup(){
  Serial.begin(9600);

  flex1.Calibrate();
  flex2.Calibrate();
  flex3.Calibrate();
  flex4.Calibrate();
  flex5.Calibrate();

  Serial.print("Min Value 1: ");
  Serial.println(flex1.getMinInput());
  Serial.print("Max Value 1: ");
  Serial.println(flex1.getMaxInput());

  Serial.print("Min Value 2: ");
  Serial.println(flex2.getMinInput());
  Serial.print("Max Value 2: ");
  Serial.println(flex2.getMaxInput());

  Serial.print("Min Value 3: ");
  Serial.println(flex3.getMinInput());
  Serial.print("Max Value 3: ");
  Serial.println(flex3.getMaxInput());

  Serial.print("Min Value 4: ");
  Serial.println(flex4.getMinInput());
  Serial.print("Max Value 4: ");
  Serial.println(flex4.getMaxInput());

  Serial.print("Min Value 5: ");
  Serial.println(flex5.getMinInput());
  Serial.print("Max Value 5: ");
  Serial.println(flex5.getMaxInput());

  delay(5000);
}

void loop(){
  flex1.updateVal();
  flex2.updateVal();
  flex3.updateVal();
  flex4.updateVal();
  flex5.updateVal();

  Serial.print("Val 1: ");
  Serial.println(flex1.getSensorValue());
  Serial.print("Val 2: ");
  Serial.println(flex2.getSensorValue());
  Serial.print("Val 3: ");
  Serial.println(flex3.getSensorValue());
  Serial.print("Val 4: ");
  Serial.println(flex4.getSensorValue());
  Serial.print("Val 5: ");
  Serial.println(flex5.getSensorValue());

  delay(1000); // Delay for 1 second
}
