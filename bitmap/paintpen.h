#ifndef PAINTPEN_H
#define PAINTPEN_H

#include <QColor>
#include <QPen>
#include "paintarea.h"

class PaintPen;
class PaintPen {
private:
    // width of the pen
    int penWidth;
    // color of the pen
    QColor penColor;
public:
    PaintPen(int width=1, QColor=Qt::black);

    QColor getPenColor() const;

    int getPenWidth() const;

    void setPenColor(QColor color);

    void setWidth(int newWidth);


};
#endif // PAINTPEN_H
