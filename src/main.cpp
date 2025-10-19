#include "poixels.h" ///< for internal esp/win differentiation
#include "log.h"     ///< for logging
#include "time.h"    ///< for timing stuff..

// #ifdef ESP32
void setup()
{
  log_init(LOG_LEVEL_INFO);
  LOG_INFO("POIXELS", "Inizializing...");

  // display = new PoixelsDisplay(LED_COUNT);
  // if (!display->begin()) {
  //     Serial.println("Failed to initialize display");
  //     return;
  // }

  // webServer = new WebServer(80, display);
  // if (!webServer->begin())
  // {
  //   Serial.println("Failed to start web server");
  //   return;
  // }
  LOG_INFO("POIXELS", "Setup finished");
}

void loop()
{
  // webServer->handleClient();
  // display->update();
  LOG_DEBUG("POIXELS", "Loop iteration complete");

  sleep(1000); // Delay for demonstration purposes
}