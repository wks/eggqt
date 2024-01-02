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
    activeLayer = &layers.emplace_back(size, 20.0);
    activeLayer->painter->fillRect(size.rectWhole(), DEFAULT_BACKGBROUND_COLOR);
}

struct EggQt {
    std::unique_ptr<DrawingContext> ctx;
    std::unique_ptr<QApplication> app;
    std::unique_ptr<EggQtMainWindow> mainWindow;
    EggQtCanvas* canvas;

    EggQt(double fWidth, double fHeight) {
        EggQtSize size = EggQtSize::fromSizeScaled(fWidth, fHeight, PIXELS_PER_CM);

        app = std::make_unique<QApplication>(argc, argv);
        mainWindow = std::make_unique<EggQtMainWindow>();
        canvas = new EggQtCanvas();
        mainWindow->setCentralWidget(canvas);

        ctx = std::make_unique<DrawingContext>(size);
        canvas->setDrawingContext(ctx.get());

        printf("mainWindow->devicePixelRatio() %lf\n", mainWindow->devicePixelRatio());
        printf("mainWindow->devicePixelRatioF() %lf\n", mainWindow->devicePixelRatioF());
        printf("canvas->devicePixelRatio() %lf\n", canvas->devicePixelRatio());
        printf("canvas->devicePixelRatioF() %lf\n", canvas->devicePixelRatioF());
        printf("mainWindow->window() %p\n", mainWindow->window());
        printf("canvas->window() %p\n", canvas->window());
        printf("mainWindow->window()->devicePixelRatio() %lf\n", mainWindow->window()->devicePixelRatio());
        printf("canvas->window()->devicePixelRatio() %lf\n", canvas->window()->devicePixelRatio());

        mainWindow->show();

        printf("mainWindow->devicePixelRatio() %lf\n", mainWindow->devicePixelRatio());
        printf("mainWindow->devicePixelRatioF() %lf\n", mainWindow->devicePixelRatioF());
        printf("canvas->devicePixelRatio() %lf\n", canvas->devicePixelRatio());
        printf("canvas->devicePixelRatioF() %lf\n", canvas->devicePixelRatioF());
        printf("mainWindow->window() %p\n", mainWindow->window());
        printf("canvas->window() %p\n", canvas->window());
        printf("mainWindow->window()->devicePixelRatio() %lf\n", mainWindow->window()->devicePixelRatio());
        printf("canvas->window()->devicePixelRatio() %lf\n", canvas->window()->devicePixelRatio());

    }
};

static EggQt* eggQt;

static EggQtLayer& activeLayer() {
    return *eggQt->ctx->activeLayer;
}

static QPainter& activePainter() {
    return *activeLayer().painter;
}

static EggQtSize& activeSize() {
    return eggQt->ctx->size;
}

static double toCanvas(double sz) {
    return activeSize().toCanvas(sz);
}

static double fromCanvas(double sz) {
    return activeSize().fromCanvas(sz);
}

static QPointF toCanvas(QPointF point) {
    return activeSize().toCanvas(point);
}

static QPointF canvasMove(QPointF point, double dx, double dy) {
    return activeSize().canvasMove(point, dx, dy);
}
void startUi(double fWidth, double fHeight) {
    eggQt = new EggQt(fWidth, fHeight);
}

void movePen(double x, double y) {
    auto& layer = activeLayer();
    layer.penCoord = QPointF(x, y);
}

void offsetPen(double dx, double dy) {
    auto& layer = activeLayer();
    layer.penCoord += QPointF(dx, dy);
}

void drawLine(double dx, double dy) {
    auto& layer = activeLayer();
    QPointF oldCoord = layer.penCoord;
    QPointF newCoord = oldCoord + QPointF(dx, dy);
    layer.painter->drawLine(toCanvas(oldCoord), toCanvas(newCoord));
    layer.penCoord = newCoord;
}

static QTextOption getDefaultTextOption() {
    QTextOption option;
    option.setAlignment(Qt::AlignLeft | Qt::AlignTop);
    option.setWrapMode(QTextOption::NoWrap);
    return option;
}

void drawString(char* pString) {
    auto& layer = activeLayer();
    QPointF topLeft = toCanvas(layer.penCoord);
    QRectF smallRect = QRectF(topLeft, QSizeF(0, 0));
    QRectF boundingRect = layer.painter->boundingRect(smallRect, pString, getDefaultTextOption());
    layer.painter->drawText(boundingRect, pString, getDefaultTextOption());
}

double getStringWidth(char* pString) {
    auto& layer = activeLayer();
    QPointF topLeft = toCanvas(layer.penCoord);
    QRectF smallRect = QRectF(topLeft, QSizeF(0, 0));
    QRectF boundingRect = layer.painter->boundingRect(smallRect, pString, getDefaultTextOption());
    return fromCanvas(boundingRect.width());
}

void drawArc(double r, double dStart, double dSweep) {
    auto& layer = activeLayer();
    auto& size = activeSize();

    double rCanvas = size.toCanvas(r);
    QPointF center = size.toCanvas(layer.penCoord);
    QPointF topLeft(center.x() - rCanvas, center.y() - rCanvas);
    QRectF arcRect(topLeft, QSizeF(rCanvas * 2.0, rCanvas * 2.0));
    printf("arcRect: %lf %lf %lf %lf\n", arcRect.left(), arcRect.top(), arcRect.right(), arcRect.bottom());

    int startAngle = dStart * 16;
    int spanAngle = dSweep * 16;
    printf("Angles: %d %d\n", startAngle, spanAngle);

    layer.painter->drawArc(arcRect, startAngle, spanAngle);
}

void drawEllipticalArc(double rx, double ry, double dStart, double dSweep) {
    auto& layer = activeLayer();
    auto& size = activeSize();

    double rxCanvas = size.toCanvas(rx);
    double ryCanvas = size.toCanvas(ry);
    QPointF center = size.toCanvas(layer.penCoord);
    QPointF topLeft(center.x() - rxCanvas, center.y() - ryCanvas);
    QRectF arcRect(topLeft, QSizeF(rxCanvas * 2.0, ryCanvas * 2.0));
    printf("ellipticalArcRect: %lf %lf %lf %lf\n", arcRect.left(), arcRect.top(), arcRect.right(), arcRect.bottom());

    int startAngle = dStart * 16;
    int spanAngle = dSweep * 16;
    printf("Angles: %d %d\n", startAngle, spanAngle);

    layer.painter->drawArc(arcRect, startAngle, spanAngle);

}

void waitForExit() {
    assert(eggQt != nullptr);
    eggQt->app->exec();
}

} // namespace eggqt
