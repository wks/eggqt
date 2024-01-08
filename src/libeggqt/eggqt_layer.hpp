#pragma once

#include <QPixmap>
#include <QPicture>
#include <QPainter>

#include "eggqt_aux.hpp"

namespace eggqt {

class EggQtLayer {
public:
    std::unique_ptr<QPixmap> pixmap;
    std::unique_ptr<QPainter> painter;

    /** The top left corner of the layer on the canvas, in centimeters. */
    QPointF anchor;
    /** Pen coordinate, in centimeters. */
    QPointF penCoord;

    EggQtLayer(const EggQtSize& size, double dpr, QPen& pen);
    EggQtLayer(const EggQtLayer& other) = delete;
};

}
