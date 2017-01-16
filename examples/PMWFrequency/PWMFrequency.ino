/*
  Fade

  This example shows how to fade an LED on pin 9
  using the analogWrite() function.

  The analogWrite() function uses PWM, so if
  you want to change the pin you're using, be
  sure to use another PWM capable pin. On most
  Arduino, the PWM pins are identified with
  a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.
*/

//
// =======================================================================================================
// INCLUDE LIRBARIES
// =======================================================================================================
//

#include <PWMFrequency.h> // https://github.com/TheDIYGuy999/PWMFrequency

//
// =======================================================================================================
// PIN ASSIGNMENTS & GLOBAL VARIABLES
// =======================================================================================================
//

int led = 9;           // the PWM pin the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

///
// =======================================================================================================
// MAIN ARDUINO SETUP (1x during startup)
// =======================================================================================================
//

void setup() {
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);

  // PWM frequency: 32 = 984Hz (default), 8 = 3936Hz, 1 = 31488Hz
  setPWMPrescaler(9, 1);
}

//
// =======================================================================================================
// MAIN LOOP
// =======================================================================================================
//

void loop() {
  // set the brightness of pin 9:
  analogWrite(led, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(30);
}
