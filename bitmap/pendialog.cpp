#include "pendialog.h"
#include <QLabel>
#include <iostream>
using namespace std;

PenDialog::PenDialog(QWidget* parent) : QDialog(parent)
{
    // remember to change this
    this->setGeometry(400, 250, 250, 130);
    this->setWindowTitle("Edit Pen");

    /* labels */

    penButtons = new QButtonGroup(this);
    penButtons->setExclusive(true);
    dialogGrid = new QGridLayout(this);
    capStyleLabel = new QLabel("Cap Style");
    widthLabel = new QLabel("Width");

    capStyleLabel->setStyleSheet("font-weight:bold");
    widthLabel->setStyleSheet("font-weight:bold");

    // slider
    penSlider = new QSlider(this);
    penSlider->setOrientation(Qt::Horizontal);
    penSlider->setRange(0, 100);
    penSlider->setGeometry(5, 100,245, 50);
    // pen characteristics
    flatButton = new QRadioButton("Flat");
    squareButton = new QRadioButton("Square");
    roundButton = new QRadioButton("Round");

    // check only one button at a time
    roundButton->setChecked(true);

    penButtons->addButton(flatButton, FLAT_BUTTON);
    penButtons->addButton(squareButton, SQUARE_BUTTON);
    penButtons->addButton(roundButton, ROUND_BUTTON);

    dialogGrid->addWidget(capStyleLabel, 0, 0);
    dialogGrid->addWidget(flatButton, 1, 0);
    dialogGrid->addWidget(squareButton, 1, 1);
    dialogGrid->addWidget(roundButton, 1, 2);

    dialogGrid->addWidget(widthLabel, 4, 0);
    dialogGrid->addWidget(penSlider, 5, 0, -1, -1);

    connect(penButtons, SIGNAL(buttonClicked(int)), this, SLOT(setPenType(int)));
    connect(penSlider, SIGNAL(valueChanged(int)), this, SLOT(setPenWidth(int)));
    connect(penSlider, SIGNAL(sliderMoved(int)), widthLabel, SLOT(setNum(int)));

}
PenDialog::~PenDialog() {
    delete penButtons;
    penButtons = NULL;
    delete flatButton;
    delete squareButton;
    delete roundButton;
    flatButton = NULL;
    squareButton = NULL;
    roundButton = NULL;
    delete penSlider;
    penSlider = NULL;
    delete dialogGrid;
    dialogGrid = NULL;
}

void PenDialog::setPenType(int pt) {
    pen_type = pt;
}

void PenDialog::setPenWidth(int width) {
    pen_width = width;
}
