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

#include <cstdio>

#include <QtMath>

#include "egg.h"
#include "eggqt_back.hpp"

void EggStart(double fWidth, double fHeight) {
    printf("Egg is about to start. fWidth: %lf, fHeight: %lf\n", fWidth, fHeight);

    eggqt::startUi(fWidth, fHeight);
}

void MovePen(double x, double y) {
    eggqt::movePen(x, y);
}

void OffsetPen(double dx, double dy) {
    eggqt::offsetPen(dx, dy);
}

void DrawLine(double dx, double dy) {
    eggqt::drawLine(dx, dy);
}

void DrawString(char* pString) {
    eggqt::drawString(pString);
}

double GetStringWidth(char* pString) {
    return eggqt::getStringWidth(pString);
}

void DrawArc(double r, double dStart, double dSweep) {
    eggqt::drawArc(r, dStart, dSweep);
}

void DrawEllipticalArc(double rx, double ry, double dStart, double dSweep) {
    eggqt::drawEllipticalArc(rx, ry, dStart, dSweep);
}

void WaitForExit() {
    eggqt::waitForExit();
}
