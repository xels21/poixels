#ifdef ESP32
#include "log.h"

#include <Arduino.h> ///< for Serial, millis, delay

void log_platform_init(void)
{
    Serial.begin(115200);
    // Wait a bit for serial to initialize
    delay(100);
}

void log_platform_write(const char *message)
{
    Serial.print(message);
    Serial.flush(); // Ensure message is sent immediately
}

unsigned long log_platform_get_timestamp(void)
{
    return millis();
}

#endif // ESP32