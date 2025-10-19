#include "poixels.h" ///< for internal esp/win differentiation

// #ifdef ESP32
void setup() {
    _setup();
    Serial.println("Starting Poixels...");
    
    // display = new PoixelsDisplay(LED_COUNT);
    // if (!display->begin()) {
    //     Serial.println("Failed to initialize display");
    //     return;
    // }

    webServer = new WebServer(80, display);
    if (!webServer->begin()) {
        Serial.println("Failed to start web server");
        return;
    }
  }
  }

void loop() {
  _loop();
}