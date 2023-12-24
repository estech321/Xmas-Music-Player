/*********************

Based off example code for the Adafruit RGB Character LCD Shield and Library

This code was used for my 2023 Christmas gift to my parents that plays music.

**********************/

// include the library code:
#include <Wire.h>
#include <Adafruit_RGBLCDShield.h>
#include <utility/Adafruit_MCP23017.h>
#include <Arduino.h>

// Include song files as libraries:
#include <buzzermusic.cpp>


// The shield uses the I2C SCL and SDA pins. On classic Arduinos
// this is Analog 4 and 5 so you can't use those for analogRead() anymore
// However, you can connect other I2C sensors to the I2C bus and share
// the I2C bus.
Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

#define buzzer 12

// These #defines make it easy to set the backlight color
#define RED 0x1
#define YELLOW 0x3
#define GREEN 0x2
#define TEAL 0x6
#define BLUE 0x4
#define VIOLET 0x5
#define WHITE 0x7

void setup() {
  // Set buzzer pin as output:
  pinMode(buzzer, OUTPUT);
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  lcd.print("Hello, world!");
  lcd.setBacklight(WHITE);
}

uint8_t i=0;
void loop() {

  //Play melody
  playMelody();

  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  uint8_t buttons = lcd.readButtons();

  if (buttons) {
    lcd.clear();
    lcd.setCursor(0,0);
    if (buttons & BUTTON_UP) {
      lcd.print("Greensleeves");
      lcd.setBacklight(RED);
      int melody = Greensleeves;
      playMelody();
    }
    if (buttons & BUTTON_DOWN) {
      lcd.print("Rick Roll");
      lcd.setBacklight(YELLOW);
      int melody = RickRoll;
      playMelody();
    }
    if (buttons & BUTTON_LEFT) {
      lcd.print("Merry Xmas");
      lcd.setBacklight(GREEN);
      int melody = MerryChristmas;
      playMelody();
    }
    if (buttons & BUTTON_RIGHT) {
      lcd.print("Ode to Joy");
      lcd.setBacklight(TEAL);
      int melody = OdetoJoy;
      playMelody();

    }
    if (buttons & BUTTON_SELECT) {
      lcd.print("Silent Night");
      lcd.setBacklight(VIOLET);
      int melody = SilentNight;
      playMelody();
    }
  }
}
