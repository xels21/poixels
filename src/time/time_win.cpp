#ifdef WINDOWS

#include "time.h"
#include <windows.h>

void sleep_ms(int milliseconds)
{
  Sleep(static_cast<DWORD>(milliseconds));
}

#endif // WINDOWS
