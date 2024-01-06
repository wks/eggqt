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
#include <cmath>

#include "egg.h"

int main() {
    EggStart(6.0, 8.0);

    MovePen(2.0, 3.0);
    DrawLine(2.0, 0.0);
    DrawLine(0.0, 2.0);
    DrawLine(-2.0, 0.0);
    DrawLine(0.0, -2.0);

    MovePen(3.0, 4.0);
    DrawArc(1, 0, 360);

    printf("Waiting for events.\n");

    bool should_exit = false;

    while (!should_exit) {
        EVENT_TYPE event = WaitForEvent();

        switch (event) {
            case EXIT: {
                should_exit = true;
                break;
            }
            case TIMER: {
                printf("TIMER\n");
                break;
            }
            case MOUSEMOVE: {
                double x = GetMouseX();
                double y = GetMouseY();
                printf("MOUSEMOVE: %lf %lf\n", x, y);
                break;
            }
            case KEYDOWN: {
                char ch = GetStruckKey();
                printf("KEYDOWN: %d %c\n", ch, ch);
                break;
            }
            case KEYUP: {
                char ch = GetStruckKey();
                printf("KEYUP: %d %c\n", ch, ch);
                break;
            }
            default: {
                printf("Unexpected event: %d\n", event);
                abort();
            }
        }
    }

    printf("Bye!\n");

    return 0;
}
