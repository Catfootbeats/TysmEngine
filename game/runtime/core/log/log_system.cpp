#include "log_system.hpp"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Tysm {
std::shared_ptr<spdlog::logger> Log::mCoreLogger;
std::shared_ptr<spdlog::logger> Log::mClientLogger;

void Log::Init()
{
    #ifdef _DEBUG
    spdlog::set_pattern("%^[%T] %n: %v%$");

    mCoreLogger = spdlog::stdout_color_mt("TYSM");
    mCoreLogger->set_level(spdlog::level::trace);

    mClientLogger = spdlog::stdout_color_mt("GAME");
    mClientLogger->set_level(spdlog::level::trace);
    #else
    #endif // DEBUG
}
}  // namespace Tysm
