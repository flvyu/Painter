#include "rectangledialog.h"

RectangleDialog::RectangleDialog(QWidget* parent) : LineDialog(parent)
{
    this->setGeometry(300, 250, 300, 500);
    roundedCurveSlider = new QSlider(this);
    roundedCurveSlider->setOrientation(Qt::Horizontal);
    roundedCurveSlider->setRange(0, 100);
    roundedCurveSlider->setGeometry(5,130, 245, 50);

    curveSliderLabel = new QLabel("Rectangle Curve");
    fillLabel = new QLabel("Fill Color");
    shapeLabel = new QLabel("Shape Type");

    curveSliderLabel->setStyleSheet("font-weight:bold");
    fillLabel->setStyleSheet("font-weight:bold");
    shapeLabel->setStyleSheet("font-weight:bold");

    foregroundButton = new QRadioButton("Foreground");
    backgroundButton = new QRadioButton("Background");
    otherColorButton = new QRadioButton("No Fill");

    rectangle = new QRadioButton("Rectangle");
    roundedRectangle = new QRadioButton("Rounded Rectangle");
    ellipse = new QRadioButton("Ellipse");

    rectangle->setChecked(true);
    backgroundButton->setChecked(true);

    fillButtons = new QButtonGroup(this);
    shapeButtons = new QButtonGroup(this);

    fillButtons->addButton(foregroundButton, FOREGROUND);
    fillButtons->addButton(backgroundButton, BACKGROUND);
    fillButtons->addButton(otherColorButton, OTHER_COLOR);

    shapeButtons->addButton(rectangle, RECTANGLE);
    shapeButtons->addButton(roundedRectangle, ROUNDED_RECTANGLE);
    shapeButtons->addButton(ellipse, ELLIPSE);

    dialogGrid->addWidget(curveSliderLabel, 13, 0);
    dialogGrid->addWidget(roundedCurveSlider, 15, 0, 1, -1);

    dialogGrid->addWidget(fillLabel, 6, 2);
    dialogGrid->addWidget(foregroundButton, 7, 2);
    dialogGrid->addWidget(backgroundButton,8, 2);
    dialogGrid->addWidget(otherColorButton, 9, 2);

    dialogGrid->addWidget(shapeLabel, 0, 2);
    dialogGrid->addWidget(rectangle, 1, 2);
    dialogGrid->addWidget(roundedRectangle, 2, 2);
    dialogGrid->addWidget(ellipse, 3, 2);

    connect(fillButtons, SIGNAL(buttonClicked(int)), this, SLOT(setFill(int)));
    connect(shapeButtons, SIGNAL(buttonClicked(int)), this, SLOT(setShape(int)));

    connect(roundedCurveSlider, SIGNAL(valueChanged(int)), this, SLOT(setRectangleCurve(int)));
    connect(roundedCurveSlider, SIGNAL(sliderMoved(int)), curveSliderLabel, SLOT(setNum(int)));
}

RectangleDialog::~RectangleDialog() {
    delete fillButtons;
    delete shapeButtons;
    delete roundedCurveSlider;
    delete foregroundButton;
    delete backgroundButton;
    delete otherColorButton;
    delete rectangle;
    delete roundedRectangle;
    delete ellipse;
    delete curveSliderLabel;
    fillButtons = NULL;
    shapeButtons = NULL;
    roundedCurveSlider = NULL;
    foregroundButton = NULL;
    backgroundButton = NULL;
    otherColorButton = NULL;
    rectangle = NULL;
    roundedRectangle = NULL;
    ellipse = NULL;
    curveSliderLabel = NULL;
}

void RectangleDialog::setFill(int fill) {
    fill_type = fill;
}

void RectangleDialog::setShape(int shape) {
    shape_type = shape;
}

void RectangleDialog::setRectangleCurve(int curve) {
    curve_size = curve;
}
