#include "log.h"     ///< for logging
#include "time.h"    ///< for timing stuff..
#include "display.h" ///< for display handling

static Display *display;

void setup()
{
  log_init(LOG_LEVEL_INFO);
  LOG_INFO("POIXELS", "Inizializing...");

  display = new Display(LED_COUNT);

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
  display->show();
  sleep_ms(1000); // Delay for demonstration purposes
}

#ifdef WINDOWS

int main()
{
  setup();
  while (1)
  {
    loop();
  }
  return 0;
}
#endif // WINDOWS