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

qt_add_library(eggqt STATIC
    constants.hpp
    eggqt_aux.hpp
    eggqt_back.cpp
    eggqt_back.hpp
    eggqt_canvas.cpp
    eggqt_canvas.hpp
    eggqt_layer.cpp
    eggqt_layer.hpp
    eggqt_mainwindow.cpp
    eggqt_mainwindow.hpp
    lib.cpp
    )

target_include_directories(eggqt
    PUBLIC
    ../include)

target_link_libraries(eggqt
    PRIVATE
    Qt6::Core
    Qt6::Widgets
    Boost::coroutine
    fmt::fmt
    )
