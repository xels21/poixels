// src/application.cpp
#include "application.h"
#include "log.h"

PoixelsApp::PoixelsApp() : display(nullptr)
{
    // Start from defines if available, else defaults
    this->config = {
        .pixelCount = 32,
        .httpPort = 80,
        .headless = false,
        .profile = "default"};
#ifdef LED_COUNT
    this->config.pixelCount = LED_COUNT;
#endif
#ifdef WEB_PORT
    this->config.httpPort = WEB_PORT;
#endif
#ifdef HEADLESS
    this->config.headless = true;
#endif
#ifdef APP_PROFILE
    this->config.profile = APP_PROFILE;
#endif
}

PoixelsApp::~PoixelsApp()
{
    shutdown();
}

bool PoixelsApp::initialize()
{
    LOG_INFO("APP", "Initializing components...");
    LOG_INFO("APP", "Pixel Count: %d", config.pixelCount);
    LOG_INFO("APP", "HTTP Port: %d", config.httpPort);
    LOG_INFO("APP", "Headless: %s", config.headless ? "true" : "false");

    display = new Display(config.pixelCount);
    if (!display)
    {
        LOG_ERROR("APP", "Failed to create display");
        return false;
    }

    // Future: initialize web server, sensors, etc.

    LOG_INFO("APP", "All components initialized");
    return true;
}

void PoixelsApp::update()
{
    // Update all components each frame
    if (display)
    {
        display->show();
    }

    // Future: webServer->handleClients(), sensors->read(), etc.
}

void PoixelsApp::shutdown()
{
    delete display;
    display = nullptr;
    // Future: cleanup other components
}
