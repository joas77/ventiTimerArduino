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
/* just testing passing objects by
 ref in functions */
void test(LiquidCrystal &lcd)
{
  lcd.print("test"); 
}


void offState(LiquidCrystal &lcd)
{
  lcd.clear();
  lcd.print("modo OFF");
}

void timerState(LiquidCrystal &lcd)
{
   button btn = NONE;
 lcd.clear();
 lcd.print("modo timer");
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
