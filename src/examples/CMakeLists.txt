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

add_executable(hello
    hello.cpp
    )

target_include_directories(hello
    PRIVATE
    ../include
    )

target_link_libraries(hello
    eggqt
    )

add_executable(event_test
    event_test.cpp
    )

target_include_directories(event_test
    PRIVATE
    ../include
    )

target_link_libraries(event_test
    eggqt
    )

add_executable(layer_test
    layer_test.cpp
    )

target_include_directories(layer_test
    PRIVATE
    ../include
    )

target_link_libraries(layer_test
    eggqt
    )
