// api/application.h
#ifndef APPLICATION_H
#define APPLICATION_H

#include "display.h"

class PoixelsApp {
private:
    Display* display;
    
public:
    PoixelsApp();
    ~PoixelsApp();
    
    bool initialize(int pixelCount);
    void update();  // called from loop()
    void shutdown();
    
    // Component accessors (if needed)
    Display* getDisplay() { return display; }
};
#endif // APPLICATION_H