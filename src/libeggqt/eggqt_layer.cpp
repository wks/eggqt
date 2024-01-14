#include "eggqt_layer.hpp"

#include "constants.hpp"

namespace eggqt {

EggQtLayer::EggQtLayer(const EggQtSize& size, double dpr, QPen& pen) : anchor(0.0, 0.0), penCoord(0.0, 0.0) {
    pixmap = std::make_unique<QPixmap>(size.isize.width() * dpr, size.isize.height() * dpr);
    pixmap->setDevicePixelRatio(dpr);

    painter = std::make_unique<QPainter>(pixmap.get());
    painter->setRenderHint(QPainter::Antialiasing);

    painter->setPen(pen);

    QFont defaultFont;
    defaultFont.setPointSizeF(DEFAULT_FONT_POINT_SIZE);
    defaultFont.setStyle(QFont::StyleNormal);
    defaultFont.setWeight(QFont::Normal);
    painter->setFont(defaultFont);
}

}
