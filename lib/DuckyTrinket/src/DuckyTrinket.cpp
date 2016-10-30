#include <ProTrinketKeyboard.h>
#include <DuckyKeys.cpp>

void ledOn(){
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(0, HIGH);
  digitalWrite(1, HIGH);
}

void ledOff(){
  // turn the LED off by making the voltage LOW
  digitalWrite(0, LOW);
  digitalWrite(1, LOW);
}

void wait(int ms){
  int ds = 9;
  int timer = 0;
  while (timer < ms){
    TrinketKeyboard.poll();
    delay(ds);
    timer += ds;
  }
}

// Pause/Wait/Delay/timing
void DELAY(int ms){
  wait(ms);
}

void setupLED(){
  // LED OUTPUT
  pinMode(0, OUTPUT); //LED on Model B
  pinMode(1, OUTPUT); //LED on Model A
}

void setupDucky(){
  TrinketKeyboard.begin();
  TrinketKeyboard.poll();
  setupLED();
}

// ## DUCKYSCRIPT Commands ##
// Strings
void STRING(String input){

  TrinketKeyboard.print(input);
  DELAY(100);
}
void PRINT(String input){
  // alias to STRING
  STRING(input);
};
void PRINTLN(String input){
  TrinketKeyboard.println(input);
  DELAY(100);
}
void PRESS(byte key){
  TrinketKeyboard.pressKey(key);
  TrinketKeyboard.pressKey(0, 0);
  DELAY(100);
}
void PRESS(byte key, byte modifiers){
  TrinketKeyboard.pressKey(modifiers, key);
  TrinketKeyboard.pressKey(0, 0);
  DELAY(100);
}
