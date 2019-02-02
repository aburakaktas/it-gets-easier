#include <FastLED.h>
#define NUM_LEDS 2
#define DATA_PIN 6

CRGB leds[NUM_LEDS];
int currentDayIndex = 0;
char colorInput;
boolean newData = false;
int index = 0;
int hue = 0;
int counter = 0;
int reverseCheck = 0;
int maxShade = 128;
int delayTime;
char flags[NUM_LEDS];

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
  delayTime = (int)(255.0/maxShade + 0.5)*20;
  flags[index] = 5;
}

void loop() {
  for (index = 0; index < NUM_LEDS; ++index) {
    fadeLED(index,0,0,0);
  }
  delay(delayTime);
  
}


void lightLED (int ledIndex, int R, int G, int B){
  leds[ledIndex].setRGB( R, G, B);
  FastLED.show(); 
}

void fadeLED (int ledIndex, int R, int G, int B){
  if (reverseCheck == 0) {
   R = counter;
   G = maxShade-counter;
   lightLED(index,R,G,0);
   counter++;
   if (counter >= maxShade) {
     reverseCheck= 1;
   }
 } else {
   R = counter;
   G = maxShade-counter;
   lightLED(index,R,G,0);
   counter--;
   if (counter <= 0) {
     reverseCheck= 0;
   }

 }
}
