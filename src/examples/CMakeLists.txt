# Copyright (C) 2023  Kunshan Wang
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License along
# with this program; if not, write to the Free Software Foundation, Inc.,
# 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

project(eggqt-examples VERSION 1.0.0 LANGUAGES C)

set(SIMPLE_EXAMPLES
    hello
    event_test
    layer_test
    timer_test
    )

foreach(tgt IN LISTS SIMPLE_EXAMPLES)
    add_executable(${tgt}
        ${tgt}.c
        )

    target_include_directories(${tgt}
        PRIVATE
        ../include
        )

    target_link_libraries(${tgt}
        eggqt
        )
endforeach()
