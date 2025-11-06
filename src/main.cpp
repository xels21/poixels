// src/main.cpp (updated)
#include "log.h"
#include "poixels_time.h"  // renamed
#include "application.h"

static PoixelsApp app;  // Single app instance

void setup() {
    log_init(LOG_LEVEL_INFO);
    LOG_INFO("POIXELS", "Starting...");
    
    if (!app.initialize()) {
        LOG_FATAL("POIXELS", "Failed to initialize application");
        return;
    }
    
    LOG_INFO("POIXELS", "Setup finished");
}

void loop() {
    app.update();
    sleep_ms(1000);
}

#ifdef WINDOWS
int main(int argc, char** argv) {
    // Allow CLI overrides before initialization
    app.applyCLIArgs(argc, argv);

    setup();
    while (1) {
        loop();
    }
    return 0;
}
#endif