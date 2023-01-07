#include "engine.hpp"

namespace Tysm {
Engine::Engine()
{
    Tysm::Log::Init();
    TY_CORE_INFO("Log System Load!");
};

Engine::~Engine(){};

void Engine::TyInitEngine()
{
   // TyWindowCreateInfo createInfo;
   // createInfo.title = "hello tysm";
   // createInfo.is_fullscreen = false;
   // window_system->init(createInfo);
}

void Engine::run(){
    
}
}  // namespace Tysm
