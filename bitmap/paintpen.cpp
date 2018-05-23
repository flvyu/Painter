#include "paintpen.h"
using namespace std;

PaintPen::PaintPen(int width, QColor color) {
    penWidth = width;
    penColor = color;

}

QColor PaintPen::getPenColor() const {
    return penColor;
}

int PaintPen::getPenWidth() const {
    return penWidth;
}

void PaintPen::setPenColor(QColor color) {
    penColor = color;
}

void PaintPen::setWidth(int newWidth) {
    penWidth = newWidth;
}


