#ifndef PAINTAREA_H
#define PAINTAREA_H

#include <QWidget>
#include <QMouseEvent>
#include <QSize>
#include <QPainter>
#include <QPen>
#include "pendialog.h"
#include "linedialog.h"
#include "eraserdialog.h"
#include "rectangledialog.h"

// forward declaration of PaintPen
class PaintPen;

class PaintArea : public QWidget
{
    // All classes that contain signals or slots
    // must mention Q_OBJECT in their declaration.
    Q_OBJECT

public:
    ~PaintArea();
    void showDialog(int dialog);
    // elements edited from dialog

    void switchPenCap(int t);
    void switchPaintLine();
    void switchRect();

    PaintArea(QWidget *parent=0);
    // Pens for each tool that can be modified
    QPen* paintPen;
    QPen* rectanglePen;
    QPen* linePen;
    QPen* eraserPen;
    // the current pen is the pen related to the tool icon that is clicked.
    QPen *currentPen;
    /* constants to check what icon was clicked
     * this is used to display the proper toolbar
    */
    const int PEN_TOOL = 0;
    const int LINE_TOOL = 1;
    const int RECT_TOOL = 2;
    const int ERASE_TOOL = 3;
    // keeps track of currently pressed button
    int pressedButton;

    QImage getBackUpImage();
    QImage getImage();
    QPen* getPen();
    QColor* getBackgroundColor();
    QColor getforegroundColor();
    void setForegroundColor(QColor color);
    void setBackUpImage(QImage& image);
    void setImage(QImage& image);
    void currentPressedButton(int button);
    int returnButtonPressed();
    void resizeImage(QImage *image, const QSize &newSize);

    bool loadImage(const QString &filename);
    bool saveImage(const QString &filename, const char *fileformat);
    bool isChanged() const { return changed; }

    bool mousePressed;
    bool drawStarted;

public slots:
    void clearImage();
    void changeBackgroundColor(QColor color);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override; // update the paint area
    void resizeEvent(QResizeEvent *event) override;
    // used for a right-click event
#ifndef QT_NO_CONTEXTMENU
    void contextMenuEvent(QContextMenuEvent *event) override;
#endif //QT_NO_CONTEXT_MENU


private:
    bool changed;
    bool painting;
    void drawLineTo(const QPoint &endPoint);
    QImage image;
    QImage backupImage;
    QPoint lastPoint; // last position of the mouse
    QColor backgroundColor;
    QColor foregroundColor;
    QLine paintLine;
    QRect paintRect;
    // my dialogs
    PenDialog* penDialog;
    LineDialog* lineDialog;
    EraserDialog* eraserDialog;
    RectangleDialog* rectangleDialog;
    //QPainter* painter;
};

#endif // PAINTAREA_H
