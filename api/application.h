// api/application.h
#ifndef APPLICATION_H
#define APPLICATION_H

#include "display.h"

class PoixelsApp
{
private:
    Display *display;
    struct Config
    {
        int pixelCount;      // number of LEDs
        int httpPort;        // port for web server
        bool headless;       // run without hardware output
        const char *profile; // active profile name
    } config;

public:
    PoixelsApp();
    ~PoixelsApp();

    void applyCLIArgs(int argc, char **argv); // embedded is stubbed
    bool initialize();
    void update(); // called from loop()
    void shutdown();

    // Component accessors (if needed)
    Display *getDisplay() { return display; }

};
#endif // APPLICATION_H