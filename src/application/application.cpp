// src/application.cpp
#include "application.h"
#include "log.h"

PoixelsApp::PoixelsApp() : display(nullptr) {}

PoixelsApp::~PoixelsApp() {
    shutdown();
}

bool PoixelsApp::initialize(int pixelCount) {
    LOG_INFO("APP", "Initializing components...");

    display = new Display(pixelCount);
    if (!display) {
        LOG_ERROR("APP", "Failed to create display");
        return false;
    }
    
    // Future: initialize web server, sensors, etc.
    
    LOG_INFO("APP", "All components initialized");
    return true;
}

void PoixelsApp::update() {
    // Update all components each frame
    if (display) {
        display->show();
    }
    
    // Future: webServer->handleClients(), sensors->read(), etc.
}

void PoixelsApp::shutdown() {
    delete display;
    display = nullptr;
    // Future: cleanup other components
}