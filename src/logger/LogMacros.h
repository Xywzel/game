#pragma once

// This file includes things needed for logging and defines macros for it when logging is enabled
// in combilation flags. If logging is not enabled, the macros expand to empty lines and neither strings
// or logger gets included.

#ifdef DEBUG

#include "string/String.h"
#include "logger/Logger.h"

#define LOG_INFO(message, ...) logger::log(logger::Level::Info, string::format(message, __VA_ARGS__))
#define LOG_DEBUG(message, ...) logger::log(logger::Level::Debug, string::format(message, __VA_ARGS__))
#define LOG_WARNING(message, ...) logger::log(logger::Level::Warning, string::format(message, __VA_ARGS__))
#define LOG_ERROR(message, ...) logger::log(logger::Level::Error, string::format(message, __VA_ARGS__))

#else

#define LOG_INFO(message, ...)
#define LOG_DEBUG(message, ...)
#define LOG_WARNING(message, ...)
#define LOG_ERROR(message, ...)

#endif
