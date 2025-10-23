#ifdef WINDOWS

#include "poixels_time.h"
#include <windows.h>

void sleep_ms(int milliseconds)
{
  Sleep(static_cast<DWORD>(milliseconds));
}

#endif // WINDOWS
