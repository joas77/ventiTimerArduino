#ifndef _BUTTONS_H
  #define _BUTTONS_H
// define some values used by the panel and buttons


typedef enum butttons {
  RIGHT,
  UP,
  DOWN,
  LEFT,
  SELECT,
  NONE
  }button;

// read the buttons
button read_LCD_buttons()
{
 int adc_key_in = analogRead(0);      // read the value from the sensor 
 // my buttons when read are centered at these valies: 0, 144, 329, 504, 741
 // we add approx 50 to those values and check to see if we are close
 if (adc_key_in > 1000) return NONE; // We make this the 1st option for speed reasons since it will be the most likely result
 // For V1.1 us this threshold
 if (adc_key_in < 50)   return RIGHT;  
 if (adc_key_in < 250)  return UP; 
 if (adc_key_in < 450)  return DOWN; 
 if (adc_key_in < 650)  return LEFT; 
 if (adc_key_in < 850)  return SELECT;  

 // For V1.0 comment the other threshold and use the one below:
/*
 if (adc_key_in < 50)   return btnRIGHT;  
 if (adc_key_in < 195)  return btnUP; 
 if (adc_key_in < 380)  return btnDOWN; 
 if (adc_key_in < 555)  return btnLEFT; 
 if (adc_key_in < 790)  return btnSELECT;   
*/

 return NONE;  // when all others fail, return this...
}

#endif

