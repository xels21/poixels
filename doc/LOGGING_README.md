# Lightweight Cross-Platform Logging Library

A simple, efficient logging library designed for PlatformIO projects that need to run on both ESP32 and Windows platforms.

## Features

- **Cross-platform**: Works on ESP32 (Arduino framework) and Windows (native)
- **Lightweight**: Minimal memory footprint and overhead
- **Configurable**: Runtime adjustable log levels, colors, and timestamps
- **Thread-safe**: Safe for use in multi-threaded environments
- **Color support**: ANSI color codes for better readability
- **Timestamping**: Automatic timestamp generation
- **Tag support**: Optional tags for categorizing log messages

## Log Levels

- `LOG_LEVEL_DEBUG`: Detailed information for debugging
- `LOG_LEVEL_INFO`: General information messages
- `LOG_LEVEL_WARN`: Warning messages
- `LOG_LEVEL_ERROR`: Error conditions
- `LOG_LEVEL_FATAL`: Critical errors
- `LOG_LEVEL_NONE`: Disable all logging

## Usage

### Basic Setup

```c
#include "log.h"

void setup() {
    // Initialize logging with desired level
    log_init(LOG_LEVEL_DEBUG);
}
```

### Simple Logging

```c
// Simple macros (no tags)
LOGD("Debug message: value = %d", 42);
LOGI("Application started");
LOGW("Warning: low memory");
LOGE("Error: failed to connect");
LOGF("Fatal: system crash");
```

### Tagged Logging

```c
// Tagged macros for better categorization
LOG_DEBUG("SENSOR", "Temperature: %.2f°C", 23.5);
LOG_INFO("NETWORK", "Connected to WiFi: %s", ssid);
LOG_WARN("MEMORY", "Heap usage: %d%%", usage);
LOG_ERROR("SD_CARD", "Failed to mount SD card");
LOG_FATAL("SYSTEM", "Watchdog timeout");
```

### Runtime Configuration

```c
// Change log level during runtime
log_set_level(LOG_LEVEL_WARN);  // Only show warnings and above

// Disable/enable colors
log_set_colors(0);  // Disable colors
log_set_colors(1);  // Enable colors

// Disable/enable timestamps
log_set_timestamp(0);  // Disable timestamps
log_set_timestamp(1);  // Enable timestamps
```

## Platform-Specific Behavior

### ESP32
- Uses Arduino Serial for output
- Timestamps in milliseconds since boot
- Automatically initializes Serial at 115200 baud
- Colors supported in most serial monitors

### Windows
- Uses standard printf for output
- Timestamps in milliseconds since system start
- Automatic ANSI color support detection
- Colors work in modern Windows terminals

## Memory Usage

- **RAM**: ~50 bytes for configuration + 512 bytes buffer per log call
- **Flash**: ~2-3KB for the complete library
- **Stack**: 512 bytes per log call (buffer size)

## Configuration Options

You can modify these constants in `log_core.c`:

```c
char buffer[512];  // Adjust log message buffer size
```

## Example Output

```
[1234] [INFO] <SYSTEM> Application started
[1245] [DEBUG] <SENSOR> Reading temperature sensor
[1250] [WARN] <MEMORY> Low heap memory: 2048 bytes
[1255] [ERROR] <NETWORK> Connection timeout
```

## Integration with PlatformIO

The library automatically compiles the correct platform-specific code based on the build flags:
- `ESP32`: Compiles ESP32-specific logging functions
- `WINDOWS`: Compiles Windows-specific logging functions

## Thread Safety

The library is designed to be thread-safe for typical embedded use cases. Each log call is atomic at the platform level (Serial.print() on ESP32, printf() on Windows).

## Performance

- Minimal overhead when logging is disabled for a level
- Fast string formatting using snprintf
- Immediate flush to ensure messages appear promptly
- No dynamic memory allocation

## Customization

To add support for additional platforms:

1. Create a new `log_platform.c` file
2. Implement the three platform functions:
   - `log_platform_init()`
   - `log_platform_write(const char* message)`
   - `log_platform_get_timestamp()`
3. Add appropriate `#ifdef` guards for your platform

## File Structure

```
api/log.h                 - Main header file
src/log/log_core.c        - Core logging implementation
src/log/log_esp.c         - ESP32-specific implementation
src/log/log_win.c         - Windows-specific implementation
src/log/log_example.c     - Usage examples
```