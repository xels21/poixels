#ifdef ESP32
#include "display.h"
#include <Adafruit_NeoPixel.h>

struct Display::Impl
{
  Adafruit_NeoPixel strip;
  Impl(int pixelCount) : strip(pixelCount, /*pin*/ 2, NEO_GRB + NEO_KHZ800)
  {
    strip.begin();
  }
};

Display::Display(int pixelCount) : pImpl(std::make_unique<Impl>(pixelCount)) {}
Display::~Display() = default;

void Display::setPixel(int idx, RGB c)
{
  pImpl->strip.setPixelColor(idx, pImpl->strip.Color(c.r, c.g, c.b));
}
void Display::show()
{
  pImpl->strip.show();
}

#endif // ESP32