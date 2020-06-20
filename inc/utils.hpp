#pragma once

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_DEBUG
#include <spdlog/spdlog.h>
#include <filesystem>

// logger levels:
// SPDLOG_TRACE("trace, syf");
// SPDLOG_DEBUG("debug");
// SPDLOG_INFO("info");
// SPDLOG_WARN("warn, ostrzeżenie");
// SPDLOG_ERROR("error, błąd");
// SPDLOG_CRITICAL("critical, błąd krytyczny");

std::string FindPathToResources();