#ifdef WINDOWS
#include "application.h"
#include "log.h"
#include <stdlib.h>
#include <strings.h>

// Parse simple CLI arguments (only for native/Windows builds)
void PoixelsApp::applyCLIArgs(int argc, char **argv)
{
  for (int i = 1; i < argc; ++i)
  {
    const char *arg = argv[i];
    if ((strcmp(arg, "--help") == 0) || (strcmp(arg, "-h") == 0))
    {
      LOG_INFO("CLI", "Options: --pixels N --port P --profile NAME --headless");
    }
    else if (strcmp(arg, "--pixels") == 0 && i + 1 < argc)
    {
      config.pixelCount = atoi(argv[++i]);
    }
    else if (strcmp(arg, "--port") == 0 && i + 1 < argc)
    {
      config.httpPort = atoi(argv[++i]);
    }
    else if (strcmp(arg, "--profile") == 0 && i + 1 < argc)
    {
      config.profile = argv[++i];
    }
    else if (strcmp(arg, "--headless") == 0)
    {
      config.headless = true;
    }
    else
    {
      LOG_WARN("CLI", "Unknown arg: %s", arg);
    }
  }
}

#endif