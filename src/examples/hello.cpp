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
    EggStart(16.0, 12.0);

    MovePen(1, 1);
    DrawLine(0, 2);
    OffsetPen(1, 0);
    DrawLine(0, -2);

    DrawArc(2, 0, 90);

    MovePen(4, 5);
    char text[] = "Hello 世界";
    DrawString(text);
    double width = GetStringWidth(text);
    printf("Width is %lf\n", width);
    DrawLine(width, 0);

    MovePen(4, 7);
    char text2[] = "天地不仁，以万物为刍狗；圣人不仁，以百姓为刍狗。";
    DrawString(text2);
    double width2 = GetStringWidth(text2);
    printf("Width2 is %lf\n", width2);
    DrawLine(width2, 0);

    MovePen(0.0, 12.0);
    DrawArc(3.0, 0.0, 360.0);
    DrawArc(4.0, -90.0, 60.0);
    DrawArc(5.0, -60.0, 30.0);

    printf("Close the window to exit.\n");

    WaitForExit();

    printf("Bye!\n");

    return 0;
}
