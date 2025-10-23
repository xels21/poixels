#ifdef ESP32
#include "display.h"
#include <Adafruit_NeoPixel.h>

struct Display::Impl
{
  Adafruit_NeoPixel strip;
  Impl(int pixelCount) : strip(pixelCount, /*pin*/ LED_PIN, NEO_GRB + NEO_KHZ800)
  {
    strip.begin();
  }
};

Display::Display(int pixelCount) : pImpl(new Impl(pixelCount)), pixelCount(pixelCount) {}
Display::~Display() { delete pImpl; }

void Display::setPixel(int idx, RGB c)
{
  pImpl->strip.setPixelColor(idx, pImpl->strip.Color(c.r, c.g, c.b));
}
void Display::show()
{
  pImpl->strip.show();
}

#endif // ESP32