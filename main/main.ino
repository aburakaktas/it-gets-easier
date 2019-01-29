#include <FastLED.h>
#define NUM_LEDS 14
#define DATA_PIN 6

CRGB leds[NUM_LEDS];
int currentDayIndex = 0;
char colorInput;
boolean newData = false;



void setup() { 
 Serial.begin(9600);
 Serial.println("<Arduino is ready>");
        
       FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
   }

void loop() {
recvOneChar();
 showNewData();
 lightLED(2,0,0,32);
  }
  
void lightLED (int ledIndex, int R, int G, int B){
leds[ledIndex].setRGB( R, G, B);
FastLED.show(); 
}

void recvOneChar() {
 if (Serial.available() > 0) {
 colorInput = Serial.read();
 newData = true;
 }
}

void showNewData() {
 if (newData == true) {
 Serial.print("This just in ... ");
 Serial.println(colorInput);
 newData = false;
 }
}
