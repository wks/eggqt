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
    EggStart(16.0, 9.0);

    MovePen(1, 1);
    DrawLine(14, 0);
    DrawLine(0, 7);
    DrawLine(-14, 0);
    DrawLine(0, -7);

    MovePen(1, 8);
    DrawString("背景");

    HEGG obj1 = LayEgg();
    MovePen(0, 1); // 给文本留一点空间
    DrawLine(1, 0);
    DrawLine(0, 1);
    DrawLine(-1, 0);
    DrawLine(0, -1);
    DrawString("obj1");
    MoveEgg(3, 4);

    HEGG obj2 = LayEgg();
    MovePen(1, 1);
    DrawArc(1, 0, 360);
    DrawString("obj2");
    MoveEgg(11, 5);

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
                break;
            }
            case MOUSEMOVE: {
                break;
            }
            case KEYDOWN: {
                unsigned int ch = GetStruckKey();
                printf("KEYDOWN: %d %c\n", ch, (char)ch);
                switch (ch) {
                    case 'W': {
                        printf("Move obj1 up!\n");
                        SetActiveEgg(obj1);
                        OffsetEgg(0, 1);
                        break;
                    }
                    case 'S': {
                        printf("Move obj1 down!\n");
                        SetActiveEgg(obj1);
                        OffsetEgg(0, -1);
                        break;
                    }
                    case 'A': {
                        printf("Move obj1 left!\n");
                        SetActiveEgg(obj1);
                        OffsetEgg(-1, 0);
                        break;
                    }
                    case 'D': {
                        printf("Move obj1 right!\n");
                        SetActiveEgg(obj1);
                        OffsetEgg(1, 0);
                        break;
                    }
                    case 'L': {
                        printf("Move obj2 up!\n");
                        SetActiveEgg(obj2);
                        OffsetEgg(0, 1);
                        break;
                    }
                    case '.': {
                        printf("Move obj2 down!\n");
                        SetActiveEgg(obj2);
                        OffsetEgg(0, -1);
                        break;
                    }
                    case ',': {
                        printf("Move obj2 left!\n");
                        SetActiveEgg(obj2);
                        OffsetEgg(-1, 0);
                        break;
                    }
                    case '/': {
                        printf("Move obj2 right!\n");
                        SetActiveEgg(obj2);
                        OffsetEgg(1, 0);
                        break;
                    }
                }
                break;
            }
            case KEYUP: {
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
