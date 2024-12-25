#include "timer.hpp"
#include <SDL_timer.h>

namespace tysm {
Timer::Timer()
{
    //初始化各种变量
    startTicks = 0;
    pausedTicks = 0;
    paused = false;
    started = false;
}
void Timer::start()
{
    //启动计时器
    started = true;

    //将计时器设为非暂停状态
    paused = false;

    //获取当前时钟时间
    startTicks = SDL_GetTicks();
}
void Timer::stop()
{
    //停止计时器
    started = false;

    //将计时器设为非暂停状态
    paused = false;
}
int Timer::get_ticks()
{
    //如果计时器正在运行
    if (started == true) {
        //如果计时器暂停中
        if (paused == true) {
            //返回计时器暂停时的滴答数
            return pausedTicks;
        } else {
            //返回当前时间减去启动时间的差值
            return SDL_GetTicks() - startTicks;
        }
    }

    //如果计时器没有在运行
    return 0;
}
void Timer::pause()
{
    //如果计时器正在运行但没有暂停
    if ((started == true) && (paused == false)) {
        //暂停计时器
        paused = true;

        //计算暂停时的滴答数
        pausedTicks = SDL_GetTicks() - startTicks;
    }
}
void Timer::unpause()
{
    //如果计时器暂停中
    if (paused == true) {
        //取消暂停
        paused = false;

        //重置开始时间
        startTicks = SDL_GetTicks() - pausedTicks;

        //重置暂停时间
        pausedTicks = 0;
    }
}
bool Timer::is_started()
{
    return started;
}

bool Timer::is_paused()
{
    return paused;
}
} // namespace tysm
