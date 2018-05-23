#include "linedialog.h"

LineDialog::LineDialog(QWidget* parent) : QDialog(parent)
{

    this->setGeometry(300, 250, 300, 300);
    this->setWindowTitle("Edit Line");
    // create labels
    dialogGrid = new QGridLayout(this);

    lineSlider = new QSlider(this);
    lineSlider->setOrientation(Qt::Horizontal);
    lineSlider->setRange(0, 100);
    lineSlider->setGeometry(5,130, 245, 50);

    lineStyleLabel = new QLabel("Line Style");
    widthLabel = new QLabel("Width");
    drawLabel = new QLabel("Draw Type");
    capStyleLabel = new QLabel("Cap Style");
    joinStyleLabel = new QLabel("Join Type");

    lineStyleLabel->setStyleSheet("font-weight:bold");
    widthLabel->setStyleSheet("font-weight:bold");
    capStyleLabel->setStyleSheet("font-weight:bold");
    drawLabel->setStyleSheet("font-weight:bold");
    joinStyleLabel->setStyleSheet("font-weight:bold");

    joinButtons = new QButtonGroup(this);
    drawButtons = new QButtonGroup(this);
    capButtons = new QButtonGroup(this);
    styleButtons = new QButtonGroup(this);

    // join styles
    bevelJoinButton = new QRadioButton("Bevel");
    miterJoinButton = new QRadioButton("Miter");
    roundJoinButton = new QRadioButton("Round");

    // line style
    solidButton = new QRadioButton("Solid");
    dashedButton = new QRadioButton("Dashed");
    dottedButton = new QRadioButton("Dotted");
    dashDottedButton = new QRadioButton("Dash-Dotted");
    dashDotDottedButton = new QRadioButton("Dash-Dot-Dotted");

    // cap styles
    flatButton = new QRadioButton("Flat");
    squareButton = new QRadioButton("Square");
    roundButton = new QRadioButton("Round");

    // draw type
    singleButton = new QRadioButton("Single");
    polyButton = new QRadioButton("Poly");

    bevelJoinButton->setChecked(true);
    solidButton->setChecked(true);
    roundButton->setChecked(true);
    singleButton->setChecked(true);

    joinButtons->addButton(bevelJoinButton, BEVEL_JOIN);
    joinButtons->addButton(miterJoinButton, MITER_JOIN);
    joinButtons->addButton(roundJoinButton, ROUND_JOIN);

    drawButtons->addButton(singleButton, SINGLE_BUTTON);
    drawButtons->addButton(polyButton, POLY_BUTTON);

    capButtons->addButton(flatButton, FLAT_BUTTON);
    capButtons->addButton(squareButton, SQUARE_BUTTON);
    capButtons->addButton(roundButton, ROUND_BUTTON);

    styleButtons->addButton(solidButton, SOLID_STYLE);
    styleButtons->addButton(dashedButton, DOTTED_STYLE);
    styleButtons->addButton(dottedButton, DASHED_STYLE);
    styleButtons->addButton(dashDottedButton, DASH_DOTTED_STYLE);
    styleButtons->addButton(dashDotDottedButton, DASH_DOT_DOTTED_STYLE);


    dialogGrid->addWidget(lineStyleLabel, 0, 0);
    dialogGrid->addWidget(solidButton, 1, 0);
    dialogGrid->addWidget(dashedButton, 2, 0);
    dialogGrid->addWidget(dottedButton, 3, 0);
    dialogGrid->addWidget(dashDottedButton, 4, 0);
    dialogGrid->addWidget(dashDotDottedButton, 5, 0);

    // ec
    dialogGrid->addWidget(joinStyleLabel, 6, 0);
    dialogGrid->addWidget(bevelJoinButton, 7, 0);
    dialogGrid->addWidget(miterJoinButton, 8, 0);
    dialogGrid->addWidget(roundJoinButton, 9, 0);

    dialogGrid->addWidget(widthLabel, 10, 0);
    dialogGrid->addWidget(lineSlider, 11, 0, 1, -1);

    dialogGrid->addWidget(capStyleLabel, 0, 1);
    dialogGrid->addWidget(flatButton, 1, 1);
    dialogGrid->addWidget(squareButton, 2, 1);
    dialogGrid->addWidget(roundButton, 3, 1);

    dialogGrid->addWidget(drawLabel, 6, 1);
    dialogGrid->addWidget(singleButton, 7, 1);
    dialogGrid->addWidget(polyButton, 8, 1);

    connect(joinButtons, SIGNAL(buttonClicked(int)), this, SLOT(setJoinType(int)));
    connect(drawButtons, SIGNAL(buttonClicked(int)), this, SLOT(setDrawType(int)));
    connect(capButtons, SIGNAL(buttonClicked(int)), this, SLOT(setCapType(int)));
    connect(lineSlider, SIGNAL(valueChanged(int)), this, SLOT(setLineWidth(int)));
    // ec
    connect(styleButtons, SIGNAL(buttonClicked(int)), this, SLOT(setStyleType(int)));
    connect(lineSlider, SIGNAL(sliderMoved(int)), widthLabel, SLOT(setNum(int)));
}

LineDialog::~LineDialog() {
    delete dialogGrid;
    dialogGrid = NULL;

    delete joinButtons;
    joinButtons = NULL;

    delete drawButtons;
    drawButtons = NULL;
    delete joinButtons;
    joinButtons = NULL;
    delete capButtons;
    capButtons = NULL;

    delete bevelJoinButton;
    bevelJoinButton = NULL;
    delete miterJoinButton;
    miterJoinButton = NULL;
    delete roundJoinButton;
    roundJoinButton = NULL;

    delete solidButton;
    solidButton = NULL;
    delete dashedButton;
    dashedButton = NULL;
    delete dottedButton;
    dottedButton = NULL;

    delete dashDottedButton;
    dashDottedButton = NULL;
    delete dashDotDottedButton;
    dashDotDottedButton = NULL;

    delete lineSlider;
    lineSlider = NULL;

    delete lineStyleLabel;
    lineStyleLabel = NULL;
    delete widthLabel;
    widthLabel = NULL;
    delete drawLabel;
    drawLabel = NULL;
    delete capStyleLabel;
    capStyleLabel = NULL;

}

void LineDialog::setJoinType(int join) {
    join_type = join;
}

void LineDialog::setDrawType(int draw) {
    draw_type = draw;
}

void LineDialog::setCapType(int cap) {
    cap_type = cap;
}

void LineDialog::setLineWidth(int width) {
    line_width = width;
}

void LineDialog::setStyleType(int style) {
    line_style = style;

}

void LineDialog::switchPaintLine(QPen* pen) {

    pen->setWidth(line_width);

    switch(cap_type) {
    case 0:
        pen->setCapStyle(Qt::FlatCap);
        break;
    case 1:
        pen->setCapStyle(Qt::SquareCap);
        break;
    case 2:
        pen->setCapStyle(Qt::RoundCap);
        break;
    default:
        pen->setCapStyle(Qt::RoundCap);
    }

    switch(join_type) {
    case 0:
        pen->setJoinStyle(Qt::BevelJoin);
        break;
    case 1:
        pen->setJoinStyle(Qt::MiterJoin);
        break;
    case 2:
        pen->setJoinStyle(Qt::RoundJoin);
        break;
    default:
        pen->setJoinStyle(Qt::RoundJoin);
        break;
    }

    switch(line_style) {
    case 0:
        pen->setStyle(Qt::SolidLine);
        break;
    case 1:
        pen->setStyle(Qt::DashLine);
        break;
    case 2:
        pen->setStyle(Qt::DotLine);
        break;
    case 3:
        pen->setStyle(Qt::DashDotLine);
        break;
    case 4:
        pen->setStyle(Qt::DashDotDotLine);
        break;
    default:
        pen->setStyle(Qt::SolidLine);
        break;
    }

    /*switch(draw_type) {
    case 0:
        paintPen->setStyle(Qt::SolidLine);
        break;
    case 1:
        paintPen->setStyle(Qt::DashLine);
        break;
    default:
        paintPen->setStyle(Qt::DotLine);
        break;*/
}


