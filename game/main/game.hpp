#pragma once

#include "engine.hpp"

namespace Tysm
{
    class Game
    {
    public:
        Game();
        ~Game();
        void start();
        void run();

    private:
        Tysm::Engine* engine;
        Tysm::WindowSystem* windowSystem;
        bool isQuit{false};
    };
    
} // namespace Tysm
