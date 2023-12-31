#pragma once

#include <cstdlib>

namespace eggqt {
struct EggQtSize {
    double fWidth;
    double fHeight;
    size_t width;
    size_t height;

    static EggQtSize fromSizeScaled(double fWidth, double fHeight, double scale) {
        return EggQtSize {
            .fWidth = fWidth,
            .fHeight = fHeight,
            .width = size_t(fWidth * scale),
            .height = size_t(fHeight * scale),
        };
    }
};
}
