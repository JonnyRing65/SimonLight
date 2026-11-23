/* 
 * Project Simon Memory Game
 * Author: Jonny, Tom, Nico
 * Date: 11/22/26
 * For comprehensive documentation and examples, please visit:
 * https://docs.particle.io/firmware/best-practices/firmware-template/
 */

// Include Particle Device OS APIs
#include "Particle.h"
#include "neopixel.h"
// ignore the error squigles

// Let Device OS manage the connection to the Particle Cloud
SYSTEM_MODE(AUTOMATIC);

// Run the application and system concurrently in separate threads
SYSTEM_THREAD(ENABLED);

// Show system, cloud connectivity, and application logs over USB
// View logs with CLI using 'particle serial monitor --follow'
SerialLogHandler logHandler(LOG_LEVEL_INFO);

// setup() runs once, when the device is first turned on
// These lines of code should appear AFTER the #include statements, and before
// the setup() function.
// IMPORTANT: Set pixel COUNT, PIN and TYPE
int PIXEL_COUNT = 3;
#define PIXEL_PIN SPI // Only use SPI or SPI1 on Photon 2 (SPI is MO or S0 pin; SPI1 is D2)
// NOTE: On the Photon 2, this must be a compiler constant!
int PIXEL_TYPE = WS2812;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

int num = 255;

void setup() {
  strip.begin();
  // Put initialization like pinMode and begin functions here
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // int PixelColorCyan = strip.Color(   0, 100, 100);
  // int PixelColorRed  = strip.Color(  80,   0,   0);
  // int PixelColorGold = strip.Color(  60,  50,   5);
    //Setup some colors, GRB version
    
    int PixelColorGreen = strip.Color( num,   0, 0);
    int PixelColorRed  = strip.Color(   0,  num,   0);
    int PixelColorBlue = strip.Color(  0,  0,   num);
    

    //Set first pixel to cyan
    strip.setPixelColor(0, PixelColorRed);
    //set second pixel to red
    strip.setPixelColor(1, PixelColorGreen);
    //set third pixel to Gopher Gold!
    strip.setPixelColor(2, PixelColorBlue);
    strip.show();
    delay(1000);  //wait 1sec

  // Example: Publish event to cloud every 10 seconds. Uncomment the next 3 lines to try it!
  // Log.info("Sending Hello World to the cloud!");
  // Particle.publish("Hello world!");
  // delay( 10 * 1000 ); // milliseconds and blocking - see docs for more info!
}
