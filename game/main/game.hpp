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
    };
    
} // namespace Tysm
