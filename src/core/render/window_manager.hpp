#pragma once

#include <SDL_video.h>
namespace tysm {
struct TyWindowCreateInfo {
    int width{1280};
    int height{720};
    const char *title{"tysm"};
    bool is_fullscreen{false};
    bool can_resize{false};
};
class WindowManager {
public:
    static void createWindow(SDL_Window *&window, TyWindowCreateInfo info);
    static void destroyWindow(SDL_Window *&window);
    static void setTitle(SDL_Window *window, const char *title);
    static void setWindowMinSize(SDL_Window *window, int w, int h);
    static void setWindowMaxSize(SDL_Window *window, int w, int h);
    static void getWindowSize(SDL_Window *window, int &w, int &h);
    static void setFullDesktop(SDL_Window *window);
    static void setIcon(SDL_Window *window, const char *path);
    static void errorMassageBox(SDL_Window *window, const char *msg);
    static void warnMassageBox(SDL_Window *window, const char *msg);
    static void infoMassageBox(SDL_Window *window, const char *msg);

private:
    WindowManager() = default;
    ~WindowManager() = default;
};
} // namespace tysm
