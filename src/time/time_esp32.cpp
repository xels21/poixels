#ifdef ESP32

#include "time.h"
#include <Arduino.h>

void sleep_ms(int milliseconds)
{
  delay(milliseconds);
}

#endif // ESP32
