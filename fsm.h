#ifndef _FSM_H
  #define _FSM_H

#include <LiquidCrystal.h>
#include "buttons.h"

static void (* vfnpState) (LiquidCrystal &lcd);

typedef enum{
    modoON = 0,
    modoOFF,
    modoTimer,
    modoInter
  }mode;
  

void onState(LiquidCrystal &lcd);
void offState(LiquidCrystal &lcd);
void timerState(LiquidCrystal &lcd);
void intermitenState(LiquidCrystal &lcd);


void offState(LiquidCrystal &lcd)
{
  lcd.clear();
  lcd.print("modo OFF");
}

void timerState(LiquidCrystal &lcd)
{
  unsigned int time_m = 30;
  unsigned long time_ms = (unsigned long)time_m * 60 * 1000;
  button btn = NONE;
  lcd.clear();
  lcd.print("modo timer");
  lcd.setCursor(0,1);
  lcd.print(time_m);
  while(btn == NONE)
  {
    btn = read_LCD_buttons(); 
  }
  switch(btn)
  {
    case UP:
      vfnpState = &onState;
      break;  
    case DOWN:
      vfnpState = &offState;
      break;
    case SELECT:
      // start timer
      /*TODO  add relay control*/
      //lcd.print(" select");
      for(unsigned int i=0; i<time_m; i++)
      {
        lcd.setCursor(0,1);
        lcd.print(--time_m);
        delay(60000);
        
      }
    default:
      break;
  }
  vfnpState(lcd);
 
}

void intermitenState(LiquidCrystal &lcd)
{
 lcd.clear();
 lcd.print("modo intermitente");  
}


void onState(LiquidCrystal &lcd)
{
  button btn = NONE;
  lcd.print("modo ON");
  while(btn == NONE)
  {
    btn = read_LCD_buttons(); 
  }
  switch(btn)
  {
    case UP:
      vfnpState = &timerState;
      break;  
    case DOWN:
      vfnpState = &offState;
      break;
    default:
      break;
  }
  vfnpState(lcd);
}


#endif
