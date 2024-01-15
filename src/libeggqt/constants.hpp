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

#include <QColor>

namespace eggqt {

const double PIXELS_PER_CM = 96.0 / 2.54;
const double DEFAULT_LINE_WIDTH = 0.05;
const QColor DEFAULT_PEN_COLOR = QColor::fromRgb(0, 0, 0);
const QColor DEFAULT_BACKGBROUND_COLOR = QColor::fromRgb(255, 255, 255);
const double DEFAULT_FONT_POINT_SIZE = 12.0;

}
