#include "eggqt_layer.hpp"

#include "constants.hpp"

namespace eggqt {

EggQtLayer::EggQtLayer(const EggQtSize& size, double dpr) {
    pixmap = std::make_unique<QPixmap>(size.width * dpr, size.height * dpr);
    pixmap->setDevicePixelRatio(dpr);
    printf("Pixmap: DPR = %lf\n", pixmap->devicePixelRatio());

    painter = std::make_unique<QPainter>(pixmap.get());
    painter->translate(0.0, double(size.height));
    painter->scale(double(PIXELS_PER_CM), -double(PIXELS_PER_CM));
    painter->setRenderHint(QPainter::Antialiasing);

    QPen defaultPen(DEFAULT_PEN_COLOR);
    defaultPen.setWidthF(0.05);
    defaultPen.setStyle(Qt::PenStyle::SolidLine);
    painter->setPen(QPen(defaultPen));
}

}
