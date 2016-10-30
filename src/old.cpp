/*
ProTrinketKeyboard example
For Pro Trinket (ATmega328 based Trinket) by Adafruit Industries
Please use library TrinketKeyboard for the ATtiny85 based Trinket
Version 1.0  2015-01-01 Initial Version derived from TrinketKeyBoardExample  Mike Barela
*/
#include <Arduino.h>
#include <ProTrinketKeyboard.h>  // Ensure the library is installed and the usbdrvarm.asm file is removed

// Switches are connected from ground to these defined pins
const int PIN_BUTTON_CAPITAL_A = 12;
const int PIN_BUTTON_STRING    = 11;

int flag=0;

void wait(int ms); //function declaration
void runScript(); //function declarationA


void setup(){
  // Declare button pins as inputs
  pinMode(PIN_BUTTON_CAPITAL_A, INPUT);
  pinMode(PIN_BUTTON_STRING,    INPUT);

  // setting input pins to high means turning on internal pull-up resistors
  digitalWrite(PIN_BUTTON_CAPITAL_A, HIGH);
  digitalWrite(PIN_BUTTON_STRING,    HIGH);
  // remember, the buttons are active-low, they read LOW when they are not pressed

  // start USB stuff
  TrinketKeyboard.begin();
}

void wait(int ms){
  int ds = 10;
  int timer = 0;
  while (timer < ms){
    TrinketKeyboard.poll();
    delay(ds);
    timer += ds;
  }
}

void loop(){
  TrinketKeyboard.poll();

  if (flag == 0) {
    wait(5000);

    runScript();

    flag = 1; // Dont want to run again
  }
}

// The script goes here
void runScript(){
  // Keycode reference: https://github.com/adafruit/IRKey/blob/master/kbrd_codes.h
  TrinketKeyboard.print("echo \"Hello World\"");
  wait(1000);
  // TrinketKeyboard.pressKey(KEYCODE_MOD_LEFT_SHIFT, KEYCODE_A); // this should type a capital A
  TrinketKeyboard.pressKey(0, KEYCODE_ENTER);
  TrinketKeyboard.pressKey(0, 0); // this releases the key
  wait(3000);
}
