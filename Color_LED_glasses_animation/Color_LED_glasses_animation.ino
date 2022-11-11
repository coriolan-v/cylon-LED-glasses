// Now using Qt Py Adafruit M0 SAMD21

//#include <Adafruit_DotStar.h>
#include <SPI.h>         // COMMENT OUT THIS LINE FOR GEMMA OR TRINKET
#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN A0  // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 9  // 2022 version

//Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ400  );
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
//Adafruit_DotStar pixels(NUMPIXELS, PIN_BACK_DATA, PIN_BACK_CLOCK, DOTSTAR_GBR);

#define DELAYVAL 35  // Time (in milliseconds) to pause between pixels

void setup() {
  pixels.begin();  // INITIALIZE NeoPixel strip object (REQUIRED)

  pixels.clear();  // Set all pixel colors to 'off'
}

void loop() {
  

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for (int i = 0; i < NUMPIXELS; i++) {  // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
     pixels.setPixelColor(i-1, pixels.Color(0, 0, 0));

    pixels.show();  // Send the updated pixel colors to the hardware.

    delay(DELAYVAL);  // Pause before next pass through loop
  }

  for (int i = NUMPIXELS; i >= -1; i--) {  // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels.setPixelColor(i, pixels.Color(255, 0, 0));
    pixels.setPixelColor(i+1, pixels.Color(0, 0, 0));

    pixels.show();  // Send the updated pixel colors to the hardware.

    delay(DELAYVAL);  // Pause before next pass through loop
  }

  delay(1000);
}
