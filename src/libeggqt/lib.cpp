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

#include <fmt/core.h>

#include <QtMath>

#include "egg.h"
#include "eggqt_back.hpp"

void EggStart(double fWidth, double fHeight) {
    fmt::print("Egg is about to start. fWidth: {}, fHeight: {}\n", fWidth, fHeight);

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

EVENT_TYPE WaitForEvent() {
    eggqt::EventKind kind = eggqt::waitForEvent();
    switch (kind) {
        case eggqt::EventKind::Exit:
            return EXIT;
        case eggqt::EventKind::Timer:
            return TIMER;
        case eggqt::EventKind::MouseMove:
            return MOUSEMOVE;
        case eggqt::EventKind::KeyDown:
            return KEYDOWN;
        case eggqt::EventKind::KeyUp:
            return KEYUP;
        default:
            fmt::print(stderr, "等到了奇怪的事件: {} 。向wks去喊冤！\n", (int)kind);
            abort();
    }
}

void WaitForExit() {
    eggqt::waitForExit();
}

static std::string eventKindName(size_t var) {
    switch (var) {
        case 0:
            return "键盘事件";
        case 1:
            return "鼠标事件";
        default:
            fmt::print(stderr, "发现了奇怪的事件索引: {} 。向wks去喊冤！\n", var);
            abort();
    }
}

BOOL IsKeyDown(unsigned int uVKCode) try {
    return eggqt::isKeyDown(uVKCode);
} catch (const eggqt::NoEventException& e) {
    fmt::print(stderr, "事件还没发生！");
    abort();
} catch (const eggqt::WrongEventException& e) {
    fmt::print(stderr, "事件不对。需要键盘事件。等到了 {} 。\n", eventKindName(e.var));
    abort();
}

unsigned int GetStruckKey(void) try {
    return eggqt::getStruckKey();
} catch (const eggqt::NoEventException& e) {
    fmt::print(stderr, "事件还没发生！");
    abort();
} catch (const eggqt::WrongEventException& e) {
    fmt::print(stderr, "事件不对。需要键盘事件。等到了 {} 。\n", eventKindName(e.var));
    abort();
}

double GetMouseX(void) try {
    return eggqt::getMouseX();
} catch (const eggqt::NoEventException& e) {
    fmt::print(stderr, "事件还没发生！");
    abort();
} catch (const eggqt::WrongEventException& e) {
    fmt::print(stderr, "事件不对。需要鼠标事件。等到了 {} 。\n", eventKindName(e.var));
    abort();
}

double GetMouseY(void) try {
    return eggqt::getMouseY();
} catch (const eggqt::NoEventException& e) {
    fmt::print(stderr, "事件还没发生！");
    abort();
} catch (const eggqt::WrongEventException& e) {
    fmt::print(stderr, "事件不对。需要鼠标事件。等到了 {} 。\n", eventKindName(e.var));
    abort();
}
