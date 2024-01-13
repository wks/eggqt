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

cmake_minimum_required(VERSION 3.16)

project(eggqt VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)
qt_standard_project_setup()

find_package(Boost REQUIRED COMPONENTS coroutine)
find_package(fmt REQUIRED)

set(EGG_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/src/include)

add_subdirectory(src/libeggqt)
add_subdirectory(src/examples)

install(FILES ${EGG_INCLUDE_DIR}/egg.h DESTINATION include)

install(EXPORT EggQtTargets DESTINATION lib/cmake/EggQt)
install(FILES cmake/EggQtConfig.cmake DESTINATION lib/cmake/EggQt)
