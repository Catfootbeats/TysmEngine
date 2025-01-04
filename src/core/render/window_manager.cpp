#include "window_manager.hpp"
#include "log.hpp"
#include <SDL.h>
#include <SDL_messagebox.h>
#include <SDL_video.h>

namespace tysm {
void WindowManager::createWindow(SDL_Window*& window, TyWindowCreateInfo info)
{
    int flags{SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI};
    if (info.is_fullscreen)
        flags = SDL_WINDOW_FULLSCREEN_DESKTOP | flags;
    if (info.can_resize)
        flags = SDL_WINDOW_RESIZABLE | flags;

    window = SDL_CreateWindow(info.title, SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, info.width, info.height,
                              flags);
    //*m_width = info.width;
    //*m_height = info.height;
    if (!window) {
        TY_CORE_ERROR("Error creating window:", SDL_GetError());
        SDL_DestroyWindow(window);
        return;
    }
    TY_CORE_INFO("Create Window Succeed!");
}
void WindowManager::setTitle(SDL_Window *window, const char *title)
{
    SDL_SetWindowTitle(window, title);
}
void WindowManager::setWindowMinSize(SDL_Window *window, int w, int h)
{
    SDL_SetWindowMinimumSize(window, w, h);
}
void WindowManager::setWindowMaxSize(SDL_Window *window, int w, int h)
{
    SDL_SetWindowMaximumSize(window, w, h);
}
bool WindowManager::getIsFullDesktop(SDL_Window *window)
{
    if (SDL_GetWindowFlags(window) & SDL_WINDOW_FULLSCREEN_DESKTOP)
        return true;
    return false;
}

void WindowManager::setFullDesktop(SDL_Window *window)
{
    SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN_DESKTOP);
}
void WindowManager::setWindowed(SDL_Window *window)
{
    SDL_SetWindowFullscreen(window, 0);
}
void WindowManager::getWindowSize(SDL_Window *window, int &w, int &h)
{
    SDL_GetWindowSize(window, &w, &h);
}
void WindowManager::setWindowedOrFullDesktop(SDL_Window *window)
{
    if (SDL_GetWindowFlags(window) & SDL_WINDOW_FULLSCREEN_DESKTOP) {
        setWindowed(window);
        return;
    }
    setFullDesktop(window);
}
void WindowManager::setIcon(SDL_Window *window, const char *path)
{
    SDL_Surface *surface = SDL_LoadBMP(path);
    if (!surface)
        TY_CORE_FATAL("fatal to set window icon!");
    SDL_SetWindowIcon(window, surface);
    SDL_FreeSurface(surface);
}
void WindowManager::errorMassageBox(SDL_Window *window, const char *msg)
{
    TY_CORE_ERROR(msg);
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "ERROR", msg, window);
}
void WindowManager::warnMassageBox(SDL_Window *window, const char *msg)
{
    TY_CORE_WARN(msg);
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_WARNING, "WARNING", msg, window);
}
void WindowManager::infoMassageBox(SDL_Window *window, const char *msg)
{
    TY_CORE_INFO(msg);
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "INFO", msg, window);
}
} // namespace tysm
