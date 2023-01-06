#include "SDL2/SDL.h"
#include "core/log/log_system.hpp"
#include "function/render/window_system.hpp"

int init();
namespace Tysm {
class Engine {
public:
    Engine();
    ~Engine();
    void TyInitEngine();

private:
    WindowSystem* window_system;
};
}  // namespace Tysm
