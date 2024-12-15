#include "log.hpp"
#include <memory>

namespace tysm {
std::shared_ptr<spdlog::logger> Log::mCoreLogger;
std::shared_ptr<spdlog::logger> Log::mClientLogger;

void Log::Init()
{
#ifdef DEBUG
    spdlog::set_pattern("%^[%T] %n: %v%$");

    mCoreLogger = spdlog::stdout_color_mt("TYSM");
    mCoreLogger->set_level(spdlog::level::trace);

    mClientLogger = spdlog::stdout_color_mt("GAME");
    mClientLogger->set_level(spdlog::level::trace);
    TY_CORE_INFO("Log load.");
#endif // DEBUG
}
} // namespace tysm
