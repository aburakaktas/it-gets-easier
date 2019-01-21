#include <FastLED.h>
#define NUM_LEDS 120
#define DATA_PIN 6

CRGB leds[NUM_LEDS];

void setup() { 
       FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
   }

void loop() {
  for(int dot = 0; dot < NUM_LEDS; dot++) { 
      leds[dot] = CRGB::Blue;
      FastLED.show();
      // clear this led for the next time around the loop
      leds[dot] = CRGB::Red;
      delay(10);
  }
}
