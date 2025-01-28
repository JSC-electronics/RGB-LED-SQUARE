/**
******************************************************************************
* @author	  JSC electronics
* @version  1.0
* @date		  28-01-2025
* @brief	  RGB LED square example
*           This demo shows how to control RGB LED squares using Adafruit_NeoPixel library.
*           Each square has 4 rows with 4 RGB LEDs. Each row is controlled by WS2811 LED driver. 
*           That means that individual LEDs can not be adressed (only rows).
*           
*           Wiring:
*           - VCC: Connect the VCC pin of the LED squares to 12 V power supply.
*           - GND: Connect the GND pin of the LED squares to the GND of the power supply. 
*                  Optionally, you can connect the GND also to the dev board GND. 
*           - DIN: Connect the data pin of the LED squares to the dev board GPIO pin (used in this example).
*                  Logic voltage shold be 3 to 5 V DC.
*           - DOUT: Connect the DOUT pin of the LED squares to the DIN pin of the next LED square.
*		
*/

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define PIXELS_PER_SQUARE 4
#define NUMBER_OF_SQUARES 2

#define PIN 15

#define DELAYVAL 1000

Adafruit_NeoPixel pixels(NUMBER_OF_SQUARES * PIXELS_PER_SQUARE, PIN, NEO_GRB + NEO_KHZ800);

void setSquareColour(int square, int r, int g, int b);
void setAllSquaresColour(int r, int g, int b);

void setup() {
  pixels.begin();

  pixels.clear();
}

void loop() {
  uint8_t phase,r,g,b;

  // show red
  r = 255;
  g = 0;
  b = 0;
  setAllSquaresColour(r, g, b);
  delay(DELAYVAL);

  // show green
  r = 0;
  g = 255;
  b = 0;
  setAllSquaresColour(r, g, b);
  delay(DELAYVAL);

  // show blue
  r = 0;
  g = 0;
  b = 255;
  setAllSquaresColour(r, g, b);
  delay(DELAYVAL);

  // show white
  r = 255;
  g = 255;
  b = 255;
  setAllSquaresColour(r, g, b);
  delay(DELAYVAL);

  // dim white
  for(int i = 0; i <= 255; i++) {
    r = g = b = i;
    setAllSquaresColour(r, g, b);
    delay(10);
  }

  for(int i = 255; i >= 0; i--) {
    r = g = b = i;
    setAllSquaresColour(r, g, b);
    delay(10);
  } 
  delay(DELAYVAL);
}

void setSquareColour(int square, int r, int g, int b) {
  for(int i = 0; i < PIXELS_PER_SQUARE; i++) {
    pixels.setPixelColor(square * PIXELS_PER_SQUARE + i, pixels.Color(g, r, b));
  }
}

void setAllSquaresColour(int r, int g, int b) {
  for(int i = 0; i < NUMBER_OF_SQUARES; i++) {
    setSquareColour(i, r, g, b);
  }
  pixels.show();
}