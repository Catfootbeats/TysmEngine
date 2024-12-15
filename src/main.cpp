#include "core/engine.hpp"
#include <memory>

int main(int argc, char **args)
{
    std::unique_ptr<tysm::Engine> engine(new tysm::Engine);
    engine->run();
    return 0;
}
