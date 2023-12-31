#pragma once

#include <QPixmap>
#include <QPainter>

#include "eggqt_aux.hpp"

namespace eggqt {

class EggQtLayer {
public:
    std::unique_ptr<QPixmap> pixmap;
    std::unique_ptr<QPainter> painter;
    EggQtLayer(const EggQtSize& size, double dpr);
};

}
