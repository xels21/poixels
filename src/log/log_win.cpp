#ifdef WINDOWS
#include "log.h"

#include <stdio.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#include <io.h>
#define isatty _isatty
#define fileno _fileno
#else
#include <unistd.h>
#include <sys/time.h>
#endif

static int console_supports_colors = 0;

void log_platform_init(void)
{
#ifdef _WIN32
    // Enable ANSI escape sequences on Windows 10+
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    if (GetConsoleMode(hOut, &dwMode))
    {
        dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
        SetConsoleMode(hOut, dwMode);
        console_supports_colors = 1;
    }
#else
    // Check if stdout is a terminal
    console_supports_colors = isatty(fileno(stdout));
#endif
}

void log_platform_write(const char *message)
{
    printf("%s", message);
    fflush(stdout); // Ensure message is displayed immediately
}

unsigned long log_platform_get_timestamp(void)
{
#ifdef _WIN32
    return GetTickCount();
#else
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000 + tv.tv_usec / 1000;
#endif
}

#endif // WINDOWS