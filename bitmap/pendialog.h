#ifndef PENDIALOG_H
#define PENDIALOG_H
#include <QDialog>
#include <QButtonGroup>
#include <QRadioButton>
#include <QGridLayout>
#include <QSlider>
#include <QLabel>

class PenDialog: public QDialog {
    friend class LineDialog;
    Q_OBJECT
public:
    PenDialog(QWidget* parent = 0);
    ~PenDialog();
    int pen_type;
    int pen_width;

private:
    const int FLAT_BUTTON = 0;
    const int SQUARE_BUTTON = 1;
    const int ROUND_BUTTON = 2;

    QGridLayout* dialogGrid;

    QButtonGroup* penButtons;
    QButtonGroup* joinButtons;

    QSlider* penSlider;

    QRadioButton* flatButton;
    QRadioButton* squareButton;
    QRadioButton* roundButton;

    QLabel* capStyleLabel;
    QLabel* widthLabel;


public slots:
    void setPenType(int pen_type);
    void setPenWidth(int width);
};

#endif // PENDIALOG_H
