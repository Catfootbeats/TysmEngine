#pragma once

namespace tysm {
struct Vec2 {
    int x;
    int y;
};

// pos是一个长和宽的占比
struct Position {
    float xScaler;
    float yScaler;
};
struct Size {
    int w;
    int h;
};
} // namespace tysm
