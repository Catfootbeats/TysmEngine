#pragma once

namespace tysm {
struct Vec2 {
    int x;
    int y;
};

// pos是一个长和宽的占比
struct PositionScaler {
    float xScaler;
    float yScaler;
};

struct SizeScaler {
    float wScaler;
    float hScaler;
};

struct Size {
    int w;
    int h;
};
} // namespace tysm
