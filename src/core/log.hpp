#pragma once

#include <memory>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

namespace tysm {
class Log {
public:
    static void Init();

    inline static std::shared_ptr<spdlog::logger> &GetCoreLogger()
    {
        return mCoreLogger;
    }
    inline static std::shared_ptr<spdlog::logger> &GetClientLogger()
    {
        return mClientLogger;
    }

private:
    static std::shared_ptr<spdlog::logger> mCoreLogger;
    static std::shared_ptr<spdlog::logger> mClientLogger;
};
} // namespace tysm

#ifdef DEBUG
#define TY_CORE_TRACE(...) ::tysm::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TY_CORE_INFO(...) ::tysm::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TY_CORE_WARN(...) ::tysm::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TY_CORE_ERROR(...) ::tysm::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TY_CORE_FATAL(...) ::tysm::Log::GetCoreLogger()->error(__VA_ARGS__)

#define TY_TRACE(...) ::tysm::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TY_INFO(...) ::tysm::Log::GetClientLogger()->info(__VA_ARGS__)
#define TY_WARN(...) ::tysm::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TY_ERROR(...) ::tysm::Log::GetClientLogger()->error(__VA_ARGS__)
#define TY_FATAL(...) ::tysm::Log::GetClientLogger()->error(__VA_ARGS__)
#else
#define TY_CORE_TRACE(...)
#define TY_CORE_INFO(...)
#define TY_CORE_WARN(...)
#define TY_CORE_ERROR(...)
#define TY_CORE_FATAL(...)

#define TY_TRACE(...)
#define TY_INFO(...)
#define TY_WARN(...)
#define TY_ERROR(...)
#define TY_FATAL(...)
#endif // DEBUG
