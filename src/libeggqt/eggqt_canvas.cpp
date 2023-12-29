// Copyright (C) 2023  Kunshan Wang
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

#include "eggqt_canvas.hpp"

#include <QPainter>

namespace eggqt {

EggQtCanvas::EggQtCanvas(size_t width, size_t height) : width(width), height(height) {
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

void EggQtCanvas::paintEvent(QPaintEvent *event) {
    QRect rect(10, 20, 80, 60);

    QBrush whiteBrush(QColor::fromRgb(255, 255, 255));
    QPen blackPen(QColor::fromRgb(0, 0, 0));

    QPainter painter(this);
    painter.fillRect(0, 0, width, height, whiteBrush);
    painter.setPen(blackPen);
    painter.drawRect(rect);
}

QSize EggQtCanvas::sizeHint() const {
    return QSize(width, height);
}

} // namespace eggqt
