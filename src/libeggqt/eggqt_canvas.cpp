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

#include "eggqt_canvas.hpp"

#include <QPainter>

#include "constants.hpp"
#include "eggqt_aux.hpp"

namespace eggqt {

EggQtCanvas::EggQtCanvas() : ctx(nullptr) {
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setFocusPolicy(Qt::StrongFocus);
    setMouseTracking(true);
}

void EggQtCanvas::setDrawingContext(DrawingContext* ctx) {
    this->ctx = ctx;
}

void EggQtCanvas::keyPressEvent(QKeyEvent *event) {
    int ch = event->key();
    onKeyEvent(ch, true);
}

void EggQtCanvas::keyReleaseEvent(QKeyEvent *event) {
    int ch = event->key();
    onKeyEvent(ch, false);
}

void EggQtCanvas::mouseMoveEvent(QMouseEvent *event) {
    QPointF canvasPos = event->position();
    onMouseMove(canvasPos);
}

void EggQtCanvas::paintEvent(QPaintEvent *event) {
    QRectF rect(2.0, 1.0, 8.0, 6.0);

    QBrush whiteBrush(QColor::fromRgb(255, 255, 255));
    QPen blackPen(QColor::fromRgb(0, 0, 0), 0.05);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);

    for (auto &layer : ctx->layers) {
        QPointF topLeft = ctx->size.toCanvas(layer.anchor);
        painter.drawPixmap(topLeft, *layer.pixmap);
    }

    {
        auto painter = std::make_unique<QPainter>(this);
        painter->setRenderHint(QPainter::Antialiasing);

        QPen defaultPen(DEFAULT_PEN_COLOR);
        defaultPen.setWidthF(ctx->size.toCanvas(0.05));
        defaultPen.setStyle(Qt::PenStyle::SolidLine);
        painter->setPen(QPen(defaultPen));

        QFont defaultFont;
        defaultFont.setPointSizeF(DEFAULT_FONT_POINT_SIZE);
        defaultFont.setStyle(QFont::StyleNormal);
        defaultFont.setWeight(QFont::Normal);
        painter->setFont(defaultFont);
    }
}

QSize EggQtCanvas::sizeHint() const {
    return ctx->size.isize;
}

} // namespace eggqt
