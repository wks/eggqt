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

#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#include "egg.h"

int main() {
    EggStart(8.0, 8.0);

    MovePen(1, 1);
    DrawLine(6, 0);
    DrawLine(0, 6);
    DrawLine(-6, 0);
    DrawLine(0, -6);

    HEGG obj1 = LayEgg();
    SetPenColor(RED);
    MovePen(1, 7);
    DrawArc(0.5, 0, 360);
    // 别忘了，移动的时候锚点的是左上角。
    MoveEgg(3, 5);

    printf("Wait for 1 second...\n");

    WaitFor(1000);

    MoveEgg(0, 2);

    printf("Setting interval timer...\n");

    StartTimer(300);

    printf("Waiting for events.\n");

    bool should_exit = false;
    int nTimeouts = 0;

    while (!should_exit) {
        EVENT_TYPE event = WaitForEvent();

        switch (event) {
            case EXIT: {
                should_exit = true;
                break;
            }
            case TIMER: {
                if (nTimeouts == 6) {
                    StopTimer();
                    break;
                }
                nTimeouts += 1;
                MoveEgg(nTimeouts, 2);
                break;
            }
            default: {
                // ignore
            }
        }
    }

    printf("Bye!\n");


    return 0;
}
