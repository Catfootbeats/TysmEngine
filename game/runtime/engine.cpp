#include "engine.hpp"

namespace Tysm {
Engine::Engine()
{
    #ifdef _DEBUG
        Tysm::Log::Init();
    #else
    #endif
    TY_CORE_INFO("Log System Load!");
};

Engine::~Engine(){};

void Engine::TyInitEngine()
{
    
}

void Engine::run(){
    
}
}  // namespace Tysm
