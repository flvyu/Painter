#include <QApplication>
#include "paintwindow.h"
#include "pendialog.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    QWidget* pW = new PaintWindow();
    pW->show();
    return app.exec();
};
