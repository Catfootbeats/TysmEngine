#pragma once

namespace Tysm {
class Command {
public:
    ~Command();
    virtual void execute() = 0;
};
}  // namespace Tysm
