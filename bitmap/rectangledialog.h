#ifndef RECTANGLEDIALOG_H
#define RECTANGLEDIALOG_H
#include "linedialog.h"

class RectangleDialog: public LineDialog {
    Q_OBJECT
public:
    RectangleDialog(QWidget* parent=0);
    ~RectangleDialog();
    // switch Fill, Shape, Curve
    void switchFSC(QPen* pen);
    int fill_type;
    int shape_type;
    int curve_size;

private:
    const int FOREGROUND = 0;
    const int BACKGROUND = 1;
    const int OTHER_COLOR = 2;

    const int RECTANGLE = 0;
    const int ROUNDED_RECTANGLE = 1;
    const int ELLIPSE = 2;

    QButtonGroup* fillButtons;
    QButtonGroup* shapeButtons;

    QSlider *roundedCurveSlider;

    QRadioButton* foregroundButton;
    QRadioButton* backgroundButton;
    QRadioButton* otherColorButton;

    QRadioButton* rectangle;
    QRadioButton* roundedRectangle;
    QRadioButton* ellipse;

    QLabel* curveSliderLabel;
    QLabel* fillLabel;
    QLabel* shapeLabel;

public slots:
    void setFill(int fill);
    void setShape(int shape);
    void setRectangleCurve(int curve);
};

#endif // RECTANGLEDIALOG_H
