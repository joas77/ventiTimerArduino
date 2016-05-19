#include <LiquidCrystal.h>
#include "buttons.h"
#include "fsm.h"

// initialize the library with the numbers of the interface pins
const int pin_RS = 8; // arduino pin wired to LCD RS
const int pin_EN = 9; // arduino pin wired to LCD EN
const int pin_d4 = 4; // arduino pin wired to LCD d4
const int pin_d5 = 5; // arduino pin wired to LCD d5
const int pin_d6 = 6; // arduino pin wired to LCD d7
const int pin_d7 = 7; // arduino pin wired to LCD d8


LiquidCrystal lcd( pin_RS,  pin_EN,  pin_d4,  pin_d5,  pin_d6,  pin_d7);

void setup()
{
 lcd.begin(16, 2);              // start the library
 lcd.setCursor(0,0);
 lcd.print("Push "); // print a simple message
 //test(lcd);
 onState(lcd);
}
 
void loop()
{
  
}



