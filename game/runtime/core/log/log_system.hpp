#pragma once

#include "spdlog/spdlog.h"

//std
#include <iostream>
#include <memory>

namespace Tysm {
class Log {
public:
    static void Init();

    // 智能指针，自动计数，为0清除。
    // 内联函数防止过多内存
    // & 确保引用同一个
    inline static std::shared_ptr<spdlog::logger>& GetCoreLogger()
    {
        return mCoreLogger;
    }
    inline static std::shared_ptr<spdlog::logger>& GetClientLogger()
    {
        return mClientLogger;
    }

private:
    static std::shared_ptr<spdlog::logger> mCoreLogger;
    static std::shared_ptr<spdlog::logger> mClientLogger;
};
}  // namespace Tysm

//简化调用
// ...可变参数
// __VA_ARGS__调用...


#ifdef _DEBUG
#define TY_CORE_TRACE(...)      ::Tysm::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define TY_CORE_INFO(...)       ::Tysm::Log::GetCoreLogger()->info(__VA_ARGS__)
#define TY_CORE_WARN(...)       ::Tysm::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define TY_CORE_ERROR(...)      ::Tysm::Log::GetCoreLogger()->error(__VA_ARGS__)
#define TY_CORE_FATAL(...)      ::Tysm::Log::GetCoreLogger()->error(__VA_ARGS__)

#define TY_TRACE(...)      ::Tysm::Log::GetClientLogger()->trace(__VA_ARGS__)
#define TY_INFO(...)       ::Tysm::Log::GetClientLogger()->info(__VA_ARGS__)
#define TY_WARN(...)       ::Tysm::Log::GetClientLogger()->warn(__VA_ARGS__)
#define TY_ERROR(...)      ::Tysm::Log::GetClientLogger()->error(__VA_ARGS__)
#define TY_FATAL(...)      ::Tysm::Log::GetClientLogger()->error(__VA_ARGS__)
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

