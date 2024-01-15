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

#include <exception>
#include <list>

#include "constants.hpp"
#include "eggqt_aux.hpp"
#include "eggqt_layer.hpp"

namespace eggqt {

class DrawingContext {
public:
    EggQtSize size;
    QPen masterPen;
    std::list<EggQtLayer> layers;
    EggQtLayer* activeLayer;
    double devicePixelRatio;
    DrawingContext(EggQtSize size);
    EggQtLayer& newLayer();
    void setActive(EggQtLayer* layer);
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
    EventKind kind;
    WrongEventException(EventKind kind);
};

class WrongVariantException : public std::exception {
public:
    size_t var;
    WrongVariantException(size_t var);
};

void startUi(double fWidth, double fHeight);
void movePen(double x, double y);
void offsetPen(double dx, double dy);
void drawLine(double dx, double dy);
void drawString(const char* pString);
double getStringWidth(const char* pString);
void drawArc(double r, double dStart, double dSweep);
void drawEllipticalArc(double rx, double ry, double dStart, double dSweep);

EventKind waitForEvent();
void waitForExit();
bool isKeyDown(unsigned int uVKCode);
unsigned int getStruckKey(void);
double getMouseX();
double getMouseY();

EggQtLayer* layEgg();
void setActiveEgg(EggQtLayer* layer);
void moveEgg(double x, double y);
void offsetEgg(double dx, double dy);

void startTimer(unsigned int uMillisecond);

void stopTimer(void);

bool waitFor(unsigned int uMillisecond);

void setPen(unsigned long color, double fWidth);
void setPenColor(unsigned long color);
void setPenWidth(double fWidth);

} // namespace eggqt
