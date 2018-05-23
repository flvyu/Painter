#ifndef ERASERDIALOG_H
#define ERASERDIALOG_H
#include <QDialog>
#include <QSlider>
#include <QLabel>
#include <QHBoxLayout>

class EraserDialog: public QDialog {
    Q_OBJECT

public:
    EraserDialog(QWidget* parent=0);
    ~EraserDialog();
    int eraserWidth;

private:
    QLabel* eraserLabel;
    QSlider* eraserSlider;
    QHBoxLayout* eraserLayout;

public slots:
    void setEraserWidth(int width);
};

#endif // ERASERDIALOG_H
