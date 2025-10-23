#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdint.h>
#include <vector>

struct RGB
{
  uint8_t r, g, b;
  RGB() : r(0), g(0), b(0) {}
  RGB(uint8_t rr, uint8_t gg, uint8_t bb) : r(rr), g(gg), b(bb) {}
};

class Display
{
private:
  struct Impl; // forward declaration
  Impl* pImpl; // pointer to platform-specific implementation
  int pixelCount;
public:
  explicit Display(int pixelCount);
  ~Display();
  void setPixel(int idx, RGB color);
  void show();
  int getPixelCount() const { return pixelCount; }
};

#endif // DISPLAY_H