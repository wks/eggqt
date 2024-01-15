// Copyright (C) 2023,2024  Kunshan Wang
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

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
