#ifdef ESP32
#include "web.h"

#include <Arduino.h>
#if defined(ESP32) || defined(LIBRETINY)
#include <AsyncTCP.h>
#include <WiFi.h>
#elif defined(ESP8266)
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#elif defined(TARGET_RP2040) || defined(TARGET_RP2350) || defined(PICO_RP2040) || defined(PICO_RP2350)
#include <RPAsyncTCP.h>
#include <WiFi.h>
#endif

#include <ESPAsyncWebServer.h>

static AsyncWebServer server(80);
static AsyncLoggingMiddleware requestLogger;

void webserver_init(int port)
{
  server.addMiddleware(&requestLogger);

  // curl -v -H "X-Header:Foo" http://192.168.4.1/
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(200, "text/plain", "Hello, world!"); });

  server.begin();
}

void webserver_handle_requests(void)
{
  // Implementation for handling incoming web requests
}

void webserver_stop(void)
{
  // Implementation for stopping the web server
}
#endif