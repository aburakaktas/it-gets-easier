#include <FastLED.h>
#define NUM_LEDS 1
#define DATA_PIN 6

CRGB leds[NUM_LEDS];
int currentDayIndex = 0;
char colorInput;
boolean newData = false;
int index = 0;
int hue = 0;
int counter = 0;
int reverseCheck = 0;

//union {
//    struct {
//        unsigned int is_static: 1;
//        unsigned int is_extern: 1;
//        unsigned int is_auto: 1;
//    };
//    unsigned int flags;
//};


void setup() { 
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
   }

void loop() {
fadeLED(index,0,0,0);
  }
  
  
void lightLED (int ledIndex, int R, int G, int B){
leds[ledIndex].setRGB( R, G, B);
FastLED.show(); 
}

void fadeLED (int ledIndex, int R, int G, int B){
while (reverseCheck == 0) {
   R = counter;
   G = 255-counter;
   lightLED(index,R,G,0);
   counter++;
   if(counter == 255){
     reverseCheck= 1;
   };
   delay(20);
}
while (reverseCheck == 1) {
   R = counter;
   G = 255-counter;
   lightLED(index,R,G,0);
   counter--;
   if(counter == 0){
     reverseCheck= 0;
   };
   delay(20);
  
}

}
