#ifdef WINDOWS

// src/display_win.cpp
#include "display.h"
#include <iostream>

struct Display::Impl {
  std::vector<RGB> pixels;
  Impl(int pixelCount):pixels(pixelCount){}
};

Display::Display(int pixelCount): pImpl(new Impl(pixelCount)), pixelCount(pixelCount) {}
Display::~Display() { delete pImpl; }

void Display::setPixel(int idx, RGB rgb) { pImpl->pixels[idx] = rgb; }
void Display::show() {
  std::cout << "Simulated show\n";
}

#endif // WINDOWS