#include "core/engine.hpp"

int main(int argc, char **args)
{
    auto engine = new tysm::Engine;
    engine->run();
    delete engine;
    return 0;
}
