#pragma once

#include <memory>
#include <spdlog/spdlog.h>

namespace tysm {
class Log {
public:
    static void Init()
    {
#ifdef _DEBUG
        spdlog::set_pattern("%^[%T] %n: %v%$");

        mCoreLogger = spdlog::stdout_color_mt("TYSM");
        mCoreLogger->set_level(spdlog::level::trace);

        mClientLogger = spdlog::stdout_color_mt("GAME");
        mClientLogger->set_level(spdlog::level::trace);

#endif // _DEBUG
    }

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

#ifdef _DEBUG
#define TY_CORE_TRACE(...) ::Tysm::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TY_CORE_INFO(...) ::Tysm::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TY_CORE_WARN(...) ::Tysm::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TY_CORE_ERROR(...) ::Tysm::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TY_CORE_FATAL(...) ::Tysm::Log::GetCoreLogger()->error(__VA_ARGS__)

#define TY_TRACE(...) ::Tysm::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TY_INFO(...) ::Tysm::Log::GetClientLogger()->info(__VA_ARGS__)
#define TY_WARN(...) ::Tysm::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TY_ERROR(...) ::Tysm::Log::GetClientLogger()->error(__VA_ARGS__)
#define TY_FATAL(...) ::Tysm::Log::GetClientLogger()->error(__VA_ARGS__)
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
#endif // _DEBUG
