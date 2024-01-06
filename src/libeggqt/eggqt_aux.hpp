#pragma once

#include <cstdlib>

#include <QSize>
#include <QRect>
#include <QPoint>

namespace eggqt {
struct EggQtSize {
    QSizeF fSize;
    QSize isize;
    double scale;

    static EggQtSize fromSizeScaled(double fWidth, double fHeight, double scale) {
        int width = fWidth * scale;
        int height = fHeight * scale;

        return EggQtSize {
            .fSize = QSizeF(fWidth, fHeight),
            .isize = QSize(width, height),
            .scale = scale,
        };
    }

    double toCanvas(double sz) const {
        return sz * scale;
    }

    double fromCanvas(double sz) const {
        return sz / scale;
    }

    QPointF toCanvas(QPointF point) const {
        return QPointF(point.x() * scale, double(isize.height()) - point.y() * scale);
    }

    QPointF fromCanvas(QPointF point) const {
        return QPointF(point.x() / scale, (double(isize.height()) - point.y()) / scale);
    }

    QPointF canvasMove(QPointF point, double dx, double dy) const {
        return QPointF(point.x() + dx * scale, point.y() - dy * scale);
    }

    QRect rectWhole() const {
        return QRect(QPoint(0, 0), isize);
    }

    QRectF rectWholeF() const {
        return QRectF(QPointF(0.0, 0.0), isize);
    }


};
}
