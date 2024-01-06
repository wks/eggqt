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

#pragma once

#include <exception>
#include <vector>

#include "constants.hpp"
#include "eggqt_aux.hpp"
#include "eggqt_layer.hpp"

namespace eggqt {

class DrawingContext {
public:
    EggQtSize size;
    std::vector<EggQtLayer> layers;
    EggQtLayer* activeLayer;
    double devicePixelRatio;
    DrawingContext(EggQtSize size);
};

enum class EventKind {
    Exit,
    Timer,
    MouseMove,
    KeyDown,
    KeyUp,
};

class NoEventException : public std::exception {
};

class WrongEventException : public std::exception {
public:
    size_t var;
    WrongEventException(size_t var);
};

void startUi(double fWidth, double fHeight);
void movePen(double x, double y);
void offsetPen(double dx, double dy);
void drawLine(double dx, double dy);
void drawString(char* pString);
double getStringWidth(char* pString);
void drawArc(double r, double dStart, double dSweep);
void drawEllipticalArc(double rx, double ry, double dStart, double dSweep);

EventKind waitForEvent();
void waitForExit();
bool isKeyDown(unsigned int uVKCode);
unsigned int getStruckKey(void);
double getMouseX();
double getMouseY();

} // namespace eggqt
