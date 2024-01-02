#include "eggqt_layer.hpp"

#include "constants.hpp"

namespace eggqt {

EggQtLayer::EggQtLayer(const EggQtSize& size, double dpr) : penCoord(0.0, 0.0) {
    pixmap = std::make_unique<QPixmap>(size.isize.width() * dpr, size.isize.height() * dpr);
    pixmap->setDevicePixelRatio(dpr);
    printf("Pixmap: DPR = %lf\n", pixmap->devicePixelRatio());
    // pixmap = std::make_unique<QPicture>();

    painter = std::make_unique<QPainter>(pixmap.get());
    painter->setRenderHint(QPainter::Antialiasing);

    QPen defaultPen(DEFAULT_PEN_COLOR);
    defaultPen.setWidthF(size.toCanvas(0.05));
    defaultPen.setStyle(Qt::PenStyle::SolidLine);
    painter->setPen(QPen(defaultPen));

    QFont defaultFont;
    defaultFont.setPointSizeF(DEFAULT_FONT_POINT_SIZE);
    defaultFont.setStyle(QFont::StyleNormal);
    defaultFont.setWeight(QFont::Normal);
    painter->setFont(defaultFont);
}

}
