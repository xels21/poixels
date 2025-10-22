#include "log.h"
#include <string.h>

// Global log configuration
static log_config_t g_log_config = {
    .level = LOG_LEVEL_INFO,
    .enable_timestamp = 1,
    .enable_colors = 1};

// Log level strings
static const char *log_level_strings[] = {
    "DEBUG", "INFO", "WARN", "ERROR", "FATAL"};

// ANSI color codes (for terminals that support them)
static const char *log_level_colors[] = {
    "\033[36m", // DEBUG - Cyan
    "\033[32m", // INFO - Green
    "\033[33m", // WARN - Yellow
    "\033[31m", // ERROR - Red
    "\033[35m"  // FATAL - Magenta
};
static const char *color_reset = "\033[0m";

void log_init(log_level_t level)
{
    g_log_config.level = level;
    log_platform_init();
}

void log_set_level(log_level_t level)
{
    g_log_config.level = level;
}

void log_set_timestamp(int enable)
{
    g_log_config.enable_timestamp = enable;
}

void log_set_colors(int enable)
{
    g_log_config.enable_colors = enable;
}

void log_message(log_level_t level, const char *tag, const char *format, ...)
{
    // Check if message should be logged
    if (level < g_log_config.level || level >= LOG_LEVEL_NONE)
    {
        return;
    }

    char buffer[512]; // Adjust size as needed
    int offset = 0;

    // Add timestamp if enabled
    if (g_log_config.enable_timestamp)
    {
        unsigned long timestamp = log_platform_get_timestamp();
        offset += snprintf(buffer + offset, sizeof(buffer) - offset, "[%lu] ", timestamp);
    }

    // Add color if enabled
    if (g_log_config.enable_colors)
    {
        offset += snprintf(buffer + offset, sizeof(buffer) - offset, "%s", log_level_colors[level]);
    }

    // Add log level
    offset += snprintf(buffer + offset, sizeof(buffer) - offset, "[%s] ", log_level_strings[level]);

    // Add tag if provided
    if (tag && strlen(tag) > 0)
    {
        offset += snprintf(buffer + offset, sizeof(buffer) - offset, "<%s> ", tag);
    }

    // Add user message
    va_list args;
    va_start(args, format);
    offset += vsnprintf(buffer + offset, sizeof(buffer) - offset, format, args);
    va_end(args);

    // Add color reset if enabled
    if (g_log_config.enable_colors)
    {
        offset += snprintf(buffer + offset, sizeof(buffer) - offset, "%s", color_reset);
    }

    // Add newline
    if (offset < sizeof(buffer) - 1)
    {
        buffer[offset++] = '\n';
        buffer[offset] = '\0';
    }

    // Send to platform-specific output
    log_platform_write(buffer);
}