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
#include <vector>

#include <QApplication>
#include <QMainWindow>
#include <QGridLayout>
#include <QPixmap>

#include "constants.hpp"
#include "eggqt_aux.hpp"
#include "eggqt_canvas.hpp"
#include "eggqt_layer.hpp"
#include "eggqt_mainwindow.hpp"

namespace eggqt {

static int argc = 1;
static char argv0[] = "eggqt";
static char *argv[] = {argv0, nullptr};

DrawingContext::DrawingContext(EggQtSize size) : size(size) {
    activeLayer = &layers.emplace_back(size, 2.0);
}

struct EggQt {
    std::unique_ptr<DrawingContext> ctx;
    std::unique_ptr<QApplication> app;
    std::unique_ptr<EggQtMainWindow> mainWindow;
    EggQtCanvas* canvas;

    EggQt(double fWidth, double fHeight) {
        EggQtSize size = EggQtSize::fromSizeScaled(fWidth, fHeight, PIXELS_PER_CM);

        app = std::make_unique<QApplication>(argc, argv);
        ctx = std::make_unique<DrawingContext>(size);

        mainWindow = std::make_unique<EggQtMainWindow>();
        mainWindow->setLayout(new QGridLayout()); //use a layout for menu bar
        canvas = new EggQtCanvas(ctx.get());
        mainWindow->setCentralWidget(canvas);

        mainWindow->show();
    }
};

static EggQt* eggQt;

static EggQtLayer& activeLayer() {
    return *eggQt->ctx->activeLayer;
}

static QPainter& activePainter() {
    return *activeLayer().painter;
}

void startUi(double fWidth, double fHeight) {
    eggQt = new EggQt(fWidth, fHeight);

    activePainter().drawEllipse(1, 2, 5, 6);
    activePainter().drawArc(QRectF(1, 1, 3, 3), 0, 360*16);
}

void movePen(double x, double y) {
    auto& layer = activeLayer();
    layer.penCoord = QPointF(x, y);
}

void offsetPen(double dx, double dy) {
    auto& layer = activeLayer();
    QPointF oldCoord = layer.penCoord;
    QPointF newCoord(oldCoord.x() + dx, oldCoord.y() + dy);
    layer.penCoord = newCoord;
}

void drawLine(double dx, double dy) {
    auto& layer = activeLayer();
    QPointF oldCoord = layer.penCoord;
    QPointF newCoord(oldCoord.x() + dx, oldCoord.y() + dy);
    layer.painter->drawLine(oldCoord, newCoord);
    layer.penCoord = newCoord;
}

void drawArc(double r, double dStart, double dSweep) {
    auto& layer = activeLayer();
    QPointF center = layer.penCoord;
    QPointF topLeft(center.x() - r / 2, center.y() - r / 2);
    QRectF arcRect(topLeft, QSizeF(r, r));
    printf("arcRect: %lf %lf %lf %lf\n", arcRect.left(), arcRect.top(), arcRect.right(), arcRect.bottom());
    int startAngle = dStart * 16;
    int spanAngle = dSweep * 16;
    printf("Angles: %d %d\n", startAngle, spanAngle);
    layer.painter->drawArc(arcRect, startAngle, spanAngle);
}

void drawEllipticalArc(double rx, double ry, double dStart, double dSweep) {

}

void waitForExit() {
    assert(eggQt != nullptr);
    eggQt->app->exec();
}

} // namespace eggqt
