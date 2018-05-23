using namespace std;

#include <iostream>
#include <QColorDialog>
#include "paintarea.h"

/* The paint area is where the user will draw. This also takes care
 * of any functions and features related to the actual drawing.
 */
PaintArea::PaintArea(QWidget *parent) : QWidget(parent)
{

    setAttribute(Qt::WA_StaticContents);
    backgroundColor = QColor(Qt::white);
    penDialog = new PenDialog(this);
    lineDialog = new LineDialog(this);
    eraserDialog = new EraserDialog(this);
    rectangleDialog = new RectangleDialog(this);

    paintPen = new QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    linePen = new QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    rectanglePen = new QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    eraserPen = new QPen(Qt::white, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
    currentPen = paintPen;
    pressedButton = 0; // to distinguish between buttons being used

    changed = false;
    painting = false;
    mousePressed = false;
    drawStarted = false;
}

PaintArea::~PaintArea() {
    delete penDialog;
    penDialog = NULL;
    delete lineDialog;
    lineDialog = NULL;
    delete eraserDialog;
    eraserDialog = NULL;
}

void PaintArea::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        backupImage = image.copy();
        lastPoint = event->pos();
        painting = true;
        mousePressed = true;
        if (pressedButton == ERASE_TOOL)
            currentPen = eraserPen;
            currentPen->setWidth(eraserDialog->eraserWidth);

        if (pressedButton == PEN_TOOL)
            switchPenCap(penDialog->pen_type);

        if (pressedButton == LINE_TOOL) {
            paintLine.setP1(event->pos());
            paintLine.setP2(event->pos());
            // find out what line feature was selected
            switchPaintLine();
         }
         else if (pressedButton == RECT_TOOL) {
            paintRect.setTopLeft(event->pos());
            paintRect.setBottomRight(event->pos());
            // find out what rectangle feature was selected
            switchRect();
         }
    }
    return;
}

void PaintArea::mouseMoveEvent(QMouseEvent *event)
{
    // find which buttons are being pressed
    if ((event->buttons() & Qt::LeftButton) && painting) {
        if (pressedButton == LINE_TOOL) {
            image = backupImage.copy();
            paintLine.setP2(event->pos());
            QPainter painter(&image);
            painter.setRenderHint(QPainter::Antialiasing);
            currentPen = linePen;
            painter.setPen(*currentPen);
            painter.drawLine(paintLine);
        }
        else if (pressedButton == RECT_TOOL) {
              image = backupImage.copy();
              paintRect.setBottomRight(event->pos());
              QPainter painter(&image);
              painter.setRenderHint(QPainter::Antialiasing);
              currentPen = rectanglePen;
              painter.setPen(*currentPen);

              int shape_type = rectangleDialog->shape_type;
              int curve_size = rectangleDialog->curve_size;

              /* these lets you choose what type of shape you will
               * draw with the rectangle tool
              */
              switch(shape_type) {
              case 0:
                  painter.drawRect(paintRect);
                  break;
              case 1:
                  painter.drawRoundedRect(paintRect, curve_size, curve_size);
                  break;
              case 2:
                  painter.drawEllipse(paintRect);
                  break;
              default:
                  painter.drawRect(paintRect);
              }

              /* these lets you choose what type of fill
               * you will have with your rectangle
               * fill can be the background color, foreground color or none (white).
              */

              // best to use a fill with only the rectangle but not ellipses from rectangle
              // or rounded curve rectangle because it shows the rectangle and ellipse or rounded
              // rectangle in the background.
              int fill_type = rectangleDialog->fill_type;

              switch(fill_type) {
              // foregorund
              case 0:
                  painter.fillRect(paintRect, foregroundColor);
                  break;
              // background
              case 1:
                  painter.fillRect(paintRect, backgroundColor);
                  break;
              // no fill
              case 2:
                  // no fill so it is white
                  painter.fillRect(paintRect, Qt::white);
                  break;
              // background
              default:
                  // open color dialog
                  painter.fillRect(paintRect, Qt::white);
                  break;
              }


            }
        else {
             drawLineTo(event->pos());
          }
    }
    update();
}

void PaintArea::mouseReleaseEvent(QMouseEvent *event)
{
    // check the button that caused the event
   if (event->button() == Qt::LeftButton && painting) {
       if (pressedButton != LINE_TOOL && pressedButton != RECT_TOOL) {
           drawLineTo(event->pos());
           painting = false;
       }
       else {
           mousePressed = false;
           update();
       }
    }
}

void PaintArea::mouseDoubleClickEvent(QMouseEvent *event)
{
    // terminate the drawing of polyline
    if (event->button() == Qt::LeftButton) {
        // change line type
        return;
    }
    paintLine.translate(event->pos());
    return;
}

void PaintArea::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect rect = event->rect();
    painter.drawImage(rect, image, rect);
}

void PaintArea::resizeEvent(QResizeEvent *event)
{
    backupImage = image.copy();
    if (width() > image.width() || height() > image.height()){
        int nWidth = qMax(width() + 128, image.width());
        int nHeight = qMax(height() + 128, image.height());
        resizeImage(&image, QSize(nWidth, nHeight));
        update();
    }
    QWidget::resizeEvent(event);
    return;
}


bool PaintArea::loadImage(const QString &filename)
{

    QImage currentImage;
    // if image does not exist or not found return false
    if (!currentImage.load(filename))
        return false;

    QSize size = currentImage.size().expandedTo(this->size());
    resizeImage(&currentImage, size);
    image = currentImage;
    changed = false;
    // update method of QWidget
    update();
    return true;
}

// maybe give options in save for file formats
bool PaintArea::saveImage(const QString &filename, const char *format)
{
    QImage s_image = image;
    resizeImage(&s_image, size());
    // return true if image save correctly
    if (s_image.save(filename, format)) {
        // no unsaved data
        changed = false;
        return true;
    }
    else
        return false;
}

QPen* PaintArea::getPen() {
    return currentPen;
}

QColor PaintArea::getforegroundColor() {
    return foregroundColor;
}

void PaintArea::setForegroundColor(QColor color) {
    foregroundColor = color;
}

QColor* PaintArea::getBackgroundColor() {
    return &backgroundColor;
}

QImage PaintArea::getBackUpImage() {
    return backupImage;
}

QImage PaintArea::getImage() {
    return image;
}

void PaintArea::setBackUpImage(QImage& img) {
    backupImage = img;
}

void PaintArea::setImage(QImage& img) {
    image = img;
}

void PaintArea::drawLineTo(const QPoint &endPoint)
{
    QPainter painter(&image);
    // draw line from point where mouse was to last place it was
    painter.setPen(*currentPen);
    int pWidth = currentPen->width();
    painter.drawLine(lastPoint, endPoint);
    changed = true;
    int radius = (pWidth / 2) + 2;
    update(QRect(lastPoint, endPoint).normalized().adjusted(-radius, -radius, +radius, +radius));
    lastPoint = endPoint;
}

void PaintArea::resizeImage(QImage *image, const QSize &newSize)
{
    backupImage = image->copy();
    if (image->size() == newSize)
        return;
    else  {
        QImage resizedImage(newSize, QImage::Format_RGB32);
        QColor* color = getBackgroundColor();
        resizedImage.fill(*color);
        QPainter painter(&resizedImage);
        painter.drawImage(QPoint(0, 0), *image);
        *image = resizedImage;
    }
}

void PaintArea::clearImage()
{
    backupImage = image.copy();
    image.fill(qRgb(255, 255, 255));
    changed = true;
    update();
}

void PaintArea::changeBackgroundColor(QColor color) {
    backupImage = image.copy();
    image.fill(color);
    changed = true;
    backgroundColor = color;
    update();
}

void PaintArea::currentPressedButton(int button) {
    pressedButton = button;
}

int PaintArea::returnButtonPressed() {
    return pressedButton;
}
// shows the dialog box for the selected tool.
void PaintArea::showDialog(int dialog) {
    switch(dialog) {
        case 0:
            penDialog->show();
            break;
        case 1:
            lineDialog->show();
            break;
        case 2:
            rectangleDialog->show();
            break;
        case 3:
            eraserDialog->show();
            break;
        default:
            cout << "No Dialog Available" << endl;
            break;
    }
}

// this will process the right-click event
#ifndef QT_NO_CONTEXTMENU
void PaintArea::contextMenuEvent(QContextMenuEvent *event) {
    int buttonPressed = returnButtonPressed();
    showDialog(buttonPressed);
}
#endif //QT_NO_CONTEXT_MENU

void PaintArea::switchPenCap(int type) {
    switch(type) {
    case 0:
        paintPen->setCapStyle(Qt::FlatCap);
        break;
    case 1:
        paintPen->setCapStyle(Qt::SquareCap);
        break;
    case 2:
        paintPen->setCapStyle(Qt::RoundCap);
        break;
    default:
        paintPen->setCapStyle(Qt::RoundCap);
    }
    paintPen->setWidth(penDialog->pen_width);
}

void PaintArea::switchPaintLine() {
    lineDialog->switchPaintLine(linePen);
}

void PaintArea::switchRect() {
    rectangleDialog->switchPaintLine(rectanglePen);
}
