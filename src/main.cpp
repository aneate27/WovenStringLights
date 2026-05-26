#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

//which Arduino pin is connected to the LED strip
#define PIN 6

#define NUMPIXELS 100

/*
Ignore the fact that these notes are slightly stupid, as I'm becoming reacquainted with C++

Adafruit_NeoPixel - datatype (what type of object we're creating)
pixels() - object name
third parameter - bitmask configuration, meaning it mashes together multiple pieces of data into one integer
  NEO_GRB - color order (if colors are mixed up, look here)
  NEO_KHZ800 - data speed/frequency (here it's 800kHz, but may be diff for older addressable LEDs and cause it not to light up)
*/
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

struct ColorGRB {
  int g;
  int r;
  int b;
};

ColorGRB funColors(int position);

void setPixelColor(int pixelIndex, ColorGRB color) {
  pixels.setPixelColor(pixelIndex, pixels.Color(color.r, color.g, color.b));
}

#define DELAYVAL 500

void setup() {
  /*
  Initializes object in the microchip as opposed to simply memory allocation like we do above
  (it abstracts away setting the pin to output mode)
  */
  pixels.begin();
  pixels.clear();
  pixels.setBrightness(30); // Sets brightness to roughly 12% max capacity
}

void loop() {
  for (int i=0; i<NUMPIXELS; i++) {
    setPixelColor(i, funColors(i + 10));
    pixels.show();
  }
}

ColorGRB funColors(int position) {
  ColorGRB babe;
  babe.g = position;
  babe.r = position + 50;
  babe.b = position + 100;
  return babe;
}