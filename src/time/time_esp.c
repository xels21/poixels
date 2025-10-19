#ifdef ESP32

#include "time.h"

void sleep(int milliseconds)
{
  delay(milliseconds);
}
#endif // ESP32