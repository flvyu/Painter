#include "eraserdialog.h"

EraserDialog::EraserDialog(QWidget* parent) : QDialog(parent)
{
    this->setGeometry(300, 250, 300, 100);
    this->setWindowTitle("Erase Dialog");
    eraserSlider = new QSlider(this);
    eraserSlider->setOrientation(Qt::Horizontal);
    eraserSlider->setRange(0, 100);
    eraserSlider->setGeometry(5, 50, 245, 50);

    eraserLabel = new QLabel("Eraser Thickness");
    eraserLayout = new QHBoxLayout(this);

    eraserLayout->addWidget(eraserLabel);
    eraserLayout->addWidget(eraserSlider);

    connect(eraserSlider, SIGNAL(valueChanged(int)), this, SLOT(setEraserWidth(int)));
    connect(eraserSlider, SIGNAL(sliderMoved(int)), eraserLabel, SLOT(setNum(int)));
}

EraserDialog::~EraserDialog() {
    delete eraserSlider;
    eraserSlider = NULL;
    delete eraserLabel;
    eraserLabel = NULL;
    delete eraserLayout;
    eraserLayout = NULL;
}

void EraserDialog::setEraserWidth(int width) {
    eraserWidth = width;
}
