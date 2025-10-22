#ifndef LOG_H
#define LOG_H

#include <stdarg.h>
#include <stdio.h>

// Log levels
typedef enum
{
  LOG_LEVEL_DEBUG = 0,
  LOG_LEVEL_INFO,
  LOG_LEVEL_WARN,
  LOG_LEVEL_ERROR,
  LOG_LEVEL_FATAL,
  LOG_LEVEL_NONE
} log_level_t;

// Log configuration
typedef struct
{
  log_level_t level;
  int enable_timestamp;
  int enable_colors;
} log_config_t;

// Core logging functions
void log_init(log_level_t level);
void log_set_level(log_level_t level);
void log_set_timestamp(int enable);
void log_set_colors(int enable);
void log_message(log_level_t level, const char *tag, const char *format, ...);

// Platform-specific implementations
void log_platform_init(void);
void log_platform_write(const char *message);
unsigned long log_platform_get_timestamp(void);

// Convenience macros
#define LOG_DEBUG(tag, format, ...) log_message(LOG_LEVEL_DEBUG, tag, format, ##__VA_ARGS__)
#define LOG_INFO(tag, format, ...) log_message(LOG_LEVEL_INFO, tag, format, ##__VA_ARGS__)
#define LOG_WARN(tag, format, ...) log_message(LOG_LEVEL_WARN, tag, format, ##__VA_ARGS__)
#define LOG_ERROR(tag, format, ...) log_message(LOG_LEVEL_ERROR, tag, format, ##__VA_ARGS__)
#define LOG_FATAL(tag, format, ...) log_message(LOG_LEVEL_FATAL, tag, format, ##__VA_ARGS__)

// Simple macros without tags
#define LOGD(format, ...) LOG_DEBUG("", format, ##__VA_ARGS__)
#define LOGI(format, ...) LOG_INFO("", format, ##__VA_ARGS__)
#define LOGW(format, ...) LOG_WARN("", format, ##__VA_ARGS__)
#define LOGE(format, ...) LOG_ERROR("", format, ##__VA_ARGS__)
#define LOGF(format, ...) LOG_FATAL("", format, ##__VA_ARGS__)

#endif // LOG_H