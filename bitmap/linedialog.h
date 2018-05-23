#ifndef LINEDIALOG_H
#define LINEDIALOG_H
#include <QDialog>
#include <QButtonGroup>
#include <QRadioButton>
#include <QGridLayout>
#include <QSlider>
#include <QLabel>
#include <QPen>

class LineDialog: public QDialog {
    Q_OBJECT
    friend class RectangleDialog;
public:
    LineDialog(QWidget* parent=0);
    virtual ~LineDialog();
    void switchPaintLine(QPen* pen);
    int join_type;
    int line_style;
    int draw_type;
    int line_width;
    int cap_type;

private:
    // styles
    const int SOLID_STYLE = 0;
    const int DASHED_STYLE = 1;
    const int DOTTED_STYLE = 2;
    const int DASH_DOTTED_STYLE = 3;
    const int DASH_DOT_DOTTED_STYLE = 4;

    const int FLAT_BUTTON = 0;
    const int SQUARE_BUTTON = 1;
    const int ROUND_BUTTON = 2;

    const int BEVEL_JOIN = 0;
    const int MITER_JOIN = 1;
    const int ROUND_JOIN = 2;

    const int SINGLE_BUTTON = 0;
    const int POLY_BUTTON = 1;

    QGridLayout* dialogGrid;

    QButtonGroup* joinButtons;
    QButtonGroup* drawButtons;
    QButtonGroup* capButtons;
    QButtonGroup* styleButtons;

    // join buttons
    QRadioButton* bevelJoinButton;
    QRadioButton* miterJoinButton;
    QRadioButton* roundJoinButton;

    // line buttons
    QRadioButton* solidButton;
    QRadioButton* dashedButton;
    QRadioButton* dottedButton;
    QRadioButton* dashDottedButton;
    QRadioButton* dashDotDottedButton;

    // cap buttons
    QRadioButton* flatButton;
    QRadioButton* squareButton;
    QRadioButton* roundButton;
    // draw type
    QRadioButton* singleButton;
    QRadioButton* polyButton;

    QSlider* lineSlider;

    QLabel* lineStyleLabel;
    QLabel* widthLabel;
    QLabel* drawLabel;
    QLabel* capStyleLabel;
    QLabel* joinStyleLabel;

public slots:
    void setJoinType(int join);
    void setDrawType(int draw);
    void setCapType(int cap);
    void setLineWidth(int width);
    void setStyleType(int style);
};

#endif // LINEDIALOG_H
