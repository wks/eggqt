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

#include "eggqt_layer.hpp"

#include "constants.hpp"

namespace eggqt {

EggQtLayer::EggQtLayer(const EggQtSize& size, double dpr, QPen& pen) : penCoord(0.0, 0.0) {
    QPointF topLeft(0.0, size.fSize.height());
    anchor = topLeft;

    pixmap = std::make_unique<QPixmap>(size.isize.width() * dpr, size.isize.height() * dpr);
    pixmap->setDevicePixelRatio(dpr);

    painter = std::make_unique<QPainter>(pixmap.get());
    painter->setRenderHint(QPainter::Antialiasing);

    painter->setPen(pen);

    QFont defaultFont;
    defaultFont.setPointSizeF(DEFAULT_FONT_POINT_SIZE);
    defaultFont.setStyle(QFont::StyleNormal);
    defaultFont.setWeight(QFont::Normal);
    painter->setFont(defaultFont);
}

}
