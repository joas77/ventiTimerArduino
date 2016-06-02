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
void showTime(LiquidCrystal &lcd, unsigned int minutes, boolean relayStatus);


void showTime(LiquidCrystal &lcd, unsigned int minutes, boolean relayStatus)
{
 	/*TODO  add relay control*/
	lcd.setCursor(0,1);
	if(relayStatus)
	{
		lcd.print("ON ");
	}
	else
	{
		lcd.print("OFF");
	}
	
	for(unsigned int m=minutes; m!=0; m--)
	{
		lcd.setCursor(4,1);	
		if((m-1) < 10)
		{
			lcd.print("0");
			lcd.print(m-1);
		}
		else
		{
 			lcd.print(m-1);
		}
		lcd.print(":");

 	   	for(unsigned int s=60; s!=0; s--)
		{
			lcd.setCursor(7,1);
			if( (s - 1) <10)
			{
				lcd.print("0");
				lcd.print(s-1);
			}
			else
			{
				lcd.print(s-1);
			}
			delay(1000);
		}
	}	
}

void onState(LiquidCrystal &lcd)
{
  button btn = NONE;
  lcd.clear();
  lcd.print("modo ON");
	btn = getButton(); 
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

void offState(LiquidCrystal &lcd)
{
	button btn = NONE;
	lcd.clear();
	lcd.print("modo OFF");
	/*TODO: apagar relay*/
	btn = getButton();
	switch(btn)
	{
		case UP:
			vfnpState = &onState;
			break;
		case DOWN:
			vfnpState = &intermitenState;
			break;
		default:
			break;
	}
  	
	vfnpState(lcd);
}

void timerState(LiquidCrystal &lcd)
{
  	unsigned int time_m = 1;
  	button btn = NONE;
	lcd.clear();
	lcd.print("modo timer");
 	lcd.setCursor(0,1);
	lcd.print("OFF ");
	if(time_m < 10)
	{
		lcd.print("0");
		lcd.print(time_m);
	}
	else
	{
 		lcd.print(time_m);
	}
	lcd.print(":00");
 	btn = getButton(); 
 	switch(btn)
 	{
 		case UP:
 	    		vfnpState = &intermitenState;
 	     		break;  
 	   	case DOWN:
 	     		vfnpState = &onState;
 	     		break;
 	   	case SELECT:
		showTime(lcd, time_m, true);
		/*TODO: turn oof relay*/
 	   	default:
 	     		break;
 	 }
 	 vfnpState(lcd);
 
}

void intermitenState(LiquidCrystal &lcd)
{
 	button btn = NONE;
	unsigned int on_m = 2;
	unsigned int off_m = 1;
	lcd.clear();
 	lcd.print("modo intermitente");  
 	btn = getButton(); 
 	switch(btn)
 	{
 	   	case UP:
 	     		vfnpState = &offState;
 	     		break;  
 	   	case DOWN:
 	     		vfnpState = &timerState;
 	     		break;
 	   	case SELECT:
	     		while(1)
	     		{
	     			showTime(lcd, on_m, true);
	     			showTime(lcd, off_m, false);
			}
	     		break;
	   	default:
	     	break;
	}
 	 vfnpState(lcd);
}


#endif
