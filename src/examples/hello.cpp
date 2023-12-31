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

    printf("Close the window to exit.\n");

    WaitForExit();

    printf("Bye!\n");

    return 0;
}
