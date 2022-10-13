/*
  Blink without Delay

  Turns on and off a light emitting diode (LED) connected to a digital pin,
  without using the delay() function. This means that other code can run at the
  same time without being interrupted by the LED code.

  The circuit:
  - Use the onboard LED.
  - Note: Most Arduinos have an on-board LED you can control. On the UNO, MEGA
    and ZERO it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN
    is set to the correct LED pin independent of which board is used.
    If you want to know what pin the on-board LED is connected to on your
    Arduino model, check the Technical Specs of your board at:
    https://www.arduino.cc/en/Main/Products

  created 2005
  by David A. Mellis
  modified 8 Feb 2010
  by Paul Stoffregen
  modified 11 Nov 2013
  by Scott Fitzgerald
  modified 9 Jan 2017
  by Arturo Guadalupi

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/BlinkWithoutDelay
*/

#define r0 2 // pin for row 0
#define r1 3 // pin for row 1
#define r2 4 // ...
#define r3 5
#define r4 6
#define r5 7
#define r6 8
#define r7 9
#define c0 10 // pin for column 0
#define c1 11 // pin for column 1
#define c2 12 // ...
#define c3 13
#define c4 A0
#define c5 A1
#define c6 A2
#define c7 A3
int row[] = {r0, r1, r2, r3, r4, r5, r6, r7};
int column[] = {c0, c1, c2, c3, c4, c5, c6, c7};
               
void setup() {
  for(int i = 0; i<=7; i++){
    pinMode(row[i], OUTPUT);
  }
  for(int i = 0; i<=7; i++){
    pinMode(column[i], OUTPUT);
  }
  clearDisplay();
}
void loop() {
  for(int i=0; i<=7; i++){
    for(int j=0; j<=7; j++){
      switchLED(row[i],column[j],1);
      delay(100);
      switchLED(row[i],column[j],0);
    }
  }
}
void clearDisplay(){
   for(int i = 0; i<=7; i++){
      digitalWrite(row[i],LOW); 
  }
  for(int i = 0; i<=7; i++){
    digitalWrite(column[i], HIGH);
  } 
}
void switchLED(int r, int c, bool ON){
  if(ON){
    digitalWrite(r, HIGH);
    digitalWrite(c, LOW);
  }
  else{
    digitalWrite(r, LOW);
    digitalWrite(c, HIGH);
  }
}
