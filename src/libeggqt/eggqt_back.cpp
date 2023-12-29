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

#include "eggqt_back.hpp"

#include <mutex>
#include <thread>

#include <QApplication>
#include <QMainWindow>
#include <QGridLayout>

#include "eggqt_canvas.hpp"
#include "eggqt_mainwindow.hpp"

namespace eggqt {

const size_t PIXEL_PER_CM = 32;

static int argc = 1;
static char argv0[] = "eggqt";
static char *argv[] = {argv0, nullptr};

struct EggQt {
    double fWidth;
    double fHeight;
    size_t width;
    size_t height;
    std::unique_ptr<QApplication> app;
    std::unique_ptr<EggQtMainWindow> mainWindow;
    EggQtCanvas* canvas;

    EggQt(double fWidth, double fHeight) : fWidth(fWidth), fHeight(fHeight) {
        width = size_t(fWidth * PIXEL_PER_CM);
        height = size_t(fHeight * PIXEL_PER_CM);
        app = std::make_unique<QApplication>(argc, argv);
        mainWindow = std::make_unique<EggQtMainWindow>();
        mainWindow->setLayout(new QGridLayout()); //use a layout for menu bar
        canvas = new EggQtCanvas(width, height);
        mainWindow->setCentralWidget(canvas);

        mainWindow->show();
    }
};

static EggQt* eggQt;

void start_ui(double fWidth, double fHeight) {
    eggQt = new EggQt(fWidth, fHeight);
}

void wait_for_exit() {
    assert(eggQt != nullptr);
    eggQt->app->exec();
}

} // namespace eggqt
