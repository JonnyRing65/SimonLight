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
int ButtonPIN = D3;
bool ButtonNow;
bool ButtonLast;

void setup() {
  pinMode(ButtonPIN, INPUT_PULLDOWN);
  strip.begin();
  // Put initialization like pinMode and begin functions here
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  ButtonOut = digitalRead(ButtonPIN);
  ButtonNow = digitalRead(ButtonPIN);

  if(ButtonNow == HIGH && ButtonLast == LOW) {
    
    //Do our work here;
    //Set first pixel to cyan
    strip.setPixelColor(0, PixelColorRed);
    //set second pixel to red
    strip.setPixelColor(1, PixelColorGreen);
    //set third pixel to Gopher Gold!
    strip.setPixelColor(2, PixelColorBlue);
    strip.show();
    delay(1000);
    ButtonLast = HIGH;
  } else if (ButtonNow == LOW && ButtonLast == HIGH) {
    strip.setPixelColor(0, strip.Color(0, 0, 0));
    //set second pixel to red
    strip.setPixelColor(1, strip.Color(0, 0, 0));
    //set third pixel to Gopher Gold!
    strip.setPixelColor(2, strip.Color(0, 0, 0));
    strip.show();
    ButtonLast = LOW;
  }
  //Setup some colors, GRB version
    
    int PixelColorGreen = strip.Color( num,   0, 0);
    int PixelColorRed  = strip.Color(   0,  num,   0);
    int PixelColorBlue = strip.Color(  0,  0,   num);

  // Example: Publish event to cloud every 10 seconds. Uncomment the next 3 lines to try it!
  // Log.info("Sending Hello World to the cloud!");
  // Particle.publish("Hello world!");
  // delay( 10 * 1000 ); // milliseconds and blocking - see docs for more info!
}
