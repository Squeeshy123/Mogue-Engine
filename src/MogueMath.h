#pragma once
#include <cstdint>

namespace Mogue {
    struct Vector2 {
        float x;
        float y;
    };

    struct Vector3 {
        float x;
        float y;
        float z;
    };

    struct FColor {
        float r;
        float g;
        float b;
        float a;
    };
    struct IColor {
        uint8_t r;
        uint8_t g;
        uint8_t b;
        uint8_t a;
    };
}