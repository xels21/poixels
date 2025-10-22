#ifdef WINDOWS

// src/display_win.cpp
#include "display.h"
#include <iostream>

struct Display::Impl {
  int count;
  std::vector<RGB> pixels;
  Impl(int n):count(n),pixels(n){}
};

Display::Display(int pixelCount): pImpl(std::make_unique<Impl>(pixelCount)) {}
Display::~Display() = default;

void Display::setPixel(int idx, RGB c) { pImpl->pixels[idx] = c; }
void Display::show() {
  std::cout << "Simulated show\n";
}

#endif // WINDOWS