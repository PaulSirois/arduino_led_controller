#include <FastLED.h>

#define NUM_LEDS 60
#define LED_DATA 3

CRGB leds[NUM_LEDS];

uint8_t hue = 0;
int stretch = 0;

void setup() {
  delay(2000);
  FastLED.addLeds<WS2812B, LED_DATA, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);
}

void loop() {
  // solidColour(hue);
  colourSpectrum(1, 10);
  // crystalSpectrum(20, 160);
  // fastSpectrum(0, 100);
  // EVERY_N_MILLISECONDS(1000){
  //   hue++;
  // }
}

void colourSpectrum(unsigned int speed, int stretch) {
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(hue + (i*stretch), 255, 255);
  }
  if(speed) {
    EVERY_N_MILLISECONDS(speed){
      hue += 1;
    }
  }
  FastLED.show();
}

void fastSpectrum(unsigned int speed, int stretch) {
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(hue+stretch+i*3, 255, 255);
  }
  // EVERY_N_MILLISECONDS(speed){
  //   hue++;
  // }
  FastLED.show();
}

void crystalSpectrum(unsigned int speed, uint8_t hue) {
  EVERY_N_MILLISECONDS(speed) {
  leds[0] = CHSV(hue, random8(), random8(100,255));

  for(int i = NUM_LEDS - 1; i > 0; i--) {
    leds[i] = leds[i-1];
  }
  FastLED.show();
  }
}

void solidColour(uint8_t hue) {
  leds[0] = CHSV(hue, 255, 255);

  for(int i = NUM_LEDS - 1; i > 0; i--) {
    leds[i] = leds[i-1];
  }
  FastLED.show();
}

void bince() {
  
}

/*
***********************************
*         NOTES FOR PAUL          *
***********************************
  FUNCTIONS:
  FastLED.
  """"""""addLeds<>();
  """"""""show();
  """"""""setBrightness();

  EVERY_N_MICROSECONDS();/MILLISECONDS();/SECONDS();/HOURS();
  CRGB();
  CHSV();

  CONSTANTS:
  CRGB::clrConstant
clrConstant:  a constant defined in a FastLED file
*/