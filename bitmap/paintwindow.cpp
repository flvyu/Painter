using namespace std;

#include <iostream>
#include "paintwindow.h"
#include <QFileDialog>
#include <QColorDialog>
#include <QDir>
#include <QInputDialog>
#include <QMessageBox>
#include <QAction>
#include <QMenuBar>
#include <QMenu>
#include <QImageWriter>
#include <QIcon>
#include <QMenuBar>
#include <QToolButton>
#include <QToolBar>

PaintWindow::PaintWindow(QWidget* parent, const char*) :QMainWindow(parent)
{
    paintArea = new PaintArea();
    // make the paint area the center of PaintWindow
    setCentralWidget(paintArea);
    createActions();
    createMenus();
    createIconMenuBar();
    setWindowTitle(tr("Painter"));
    resize(500, 500);
}

PaintWindow::~PaintWindow() {
    delete paintArea;
    paintArea = NULL;
}

void PaintWindow::closeEvent(QCloseEvent *event) {

    if (trySave())
        event->accept();
    else
        event->ignore();
}

void PaintWindow::open() {
    if (trySave()) {
        QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QDir::currentPath());

        // file with this name was found
        if (!fileName.isEmpty())
            paintArea->loadImage(fileName);
    }
}
void PaintWindow::save() {
    // call when users choose Save as from menu
    QAction *action = qobject_cast<QAction *>(sender());
    // choose format from format menu
    QByteArray fileFormat = action->data().toByteArray();
    saveDrawing(fileFormat);
}

void PaintWindow::foregroundColor() {
    QPen* pen = paintArea->getPen();
    QColor color = pen->color();
    // grab a new color from the color dialog
    QColor newColor = QColorDialog::getColor(color, this, "Choose A new Color");
    if (newColor.isValid()) {
        pen->setColor(newColor);
        paintArea->linePen->setColor(newColor);
        paintArea->rectanglePen->setColor(newColor);
        paintArea->setForegroundColor(newColor);
     }

}

void PaintWindow::newImage() {
    // first attempt a save, clear the image;
    if (trySave()) {
        paintArea->clearImage();
        //connect(newImageButton, SIGNAL(clicked()), paintArea, slot(clearImage()));
    }
    paintArea->clearImage();
    resizeImage();
    backgroundColor();
    //connect(newImageButton, SIGNAL(clicked()), paintArea, slot(clearImage()));
}

void PaintWindow::saveAsBitmap() {
    saveDrawing("bmp");
}

void PaintWindow::backgroundColor() {
    QColor* color = paintArea->getBackgroundColor();
    QColor newColor = QColorDialog::getColor(*color, this, "Choose A Background Color");
    if (newColor.isValid())
        paintArea->changeBackgroundColor(newColor);
}

void PaintWindow::undo() {
    cout << "UNDO" << endl;
    QImage temp = paintArea->getImage().copy();
    QImage backUpImage = paintArea->getBackUpImage();
    paintArea->setImage(backUpImage);
    paintArea->setBackUpImage(temp);
    this->repaint();
}

void PaintWindow::redo() {
    cout << "REDO" << endl;
    QImage temp = paintArea->getBackUpImage();
    QImage img = paintArea->getImage();
    paintArea->setImage(temp);
    paintArea->setBackUpImage(img);
    this->repaint();
}

void PaintWindow::clearImage() {
    paintArea->clearImage();
}

void PaintWindow::penTool() {
    paintArea->currentPen = paintArea->paintPen;
    paintArea->currentPressedButton(paintArea->PEN_TOOL);
    // set the pen color back to the foreground
    paintArea->currentPen->setColor(paintArea->getforegroundColor());
}

void PaintWindow::erase() {
    // set the pen color to the background color
    paintArea->currentPen = paintArea->eraserPen;
    QColor* color = paintArea->getBackgroundColor();
    QPen* pen = paintArea->getPen();
    pen->setColor(*color);
    paintArea->currentPressedButton(paintArea->ERASE_TOOL);
}

void PaintWindow::line() {
    paintArea->currentPen = paintArea->linePen;
    paintArea->currentPressedButton(paintArea->LINE_TOOL);
}

void PaintWindow::rectangle() {
    paintArea->currentPen = paintArea->rectanglePen;
    paintArea->currentPressedButton(paintArea->RECT_TOOL);
}

void PaintWindow::resizeImage() {
    cout << "RESIZING" << endl;
    // call a QDialog to get the size
    QImage cImage = paintArea->getImage();
    paintArea->setBackUpImage(cImage);
    bool okx;
    bool oky;
    int x = QInputDialog::getInt(this, tr("Enter New Width"), tr("Width"), 0, 0, 1000, 1, &okx);
    int y = QInputDialog::getInt(this, tr("Enter New Height"), tr("Height"), 0, 0, 1000, 1, &oky);
    if (okx && oky) {
        QSize newSize(x, y);
        QImage img = paintArea->getImage();
        QImage scaledImage = img.scaled(newSize);
        paintArea->setImage(scaledImage);
        this->repaint();
    }
    else {
        return;
    }

}

void PaintWindow::setPenWidth(int newWidth) {
    QPen* pen = paintArea->getPen();
    pen->setWidth(newWidth);
}

void PaintWindow::about() {
    QMessageBox::about(this, tr("About Paint"), tr("<p><b>Painter</b> lets you create drawings and release your creativity.</p>"));
}

void PaintWindow::createActions() {
    // actions to represent menu entries and connect to slots
    openAct = new QAction(tr("&Open"), this);
    openAct->setShortcuts(QKeySequence::Open);
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    // get list of supported file formats
    foreach(QByteArray format, QImageWriter::supportedImageFormats()) {
        QString text = tr("%1...").arg(QString(format).toUpper());
        QAction *action = new QAction(text, this);
        action->setData(format);
        connect(action, SIGNAL(triggered()), this, SLOT(save()));
        saveAsActs.append(action);
    }

    exitAct = new QAction(tr("&Exit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    clearScreenAct = new QAction(tr("&Clear Screen"), this);
    clearScreenAct->setShortcut(tr("Ctrl+L"));
    connect(clearScreenAct, SIGNAL(triggered()), paintArea, SLOT(clearImage()));


    aboutAct = new QAction(tr("&About"), this);
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));


    aboutQtAct = new QAction(tr("About &Qt"), this);
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void PaintWindow::createMenus() {
    saveAsMenu = new QMenu(tr("&Save As"), this);
    foreach (QAction *action, saveAsActs)
        saveAsMenu->addAction(action);

    fileMenu = new QMenu(tr("&File"), this);
    fileMenu->addAction(openAct);
    fileMenu->addMenu(saveAsMenu);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    optionMenu = new QMenu(tr("&Options"), this);
    optionMenu->addSeparator();
    optionMenu->addAction(clearScreenAct);

    helpMenu = new QMenu(tr("&Help"), this);
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);

    menuBar()->addMenu(fileMenu);
    menuBar()->addMenu(optionMenu);
    menuBar()->addMenu(helpMenu);
    menuBar()->addAction(openAct);
}

void PaintWindow::initiateButtons() {
    newImageButton = new QToolButton;
    openButton = new QToolButton;
    saveButton = new QToolButton;
    foregroundColorButton = new QToolButton;
    backgroundColorButton = new QToolButton;
    undoButton = new QToolButton;
    redoButton = new QToolButton;
    clearImageButton = new QToolButton;
    //displayToolbarButton = new QToolButton;
    penButton = new QToolButton;
    eraserButton = new QToolButton;
    rectangleButton = new QToolButton;
    lineButton = new QToolButton;
    resizeButton = new QToolButton;
}

void PaintWindow::setButtonIcons() {
    // base directory
    QString bd = ":/paint_icons/";
    newImageButton->setIcon(QIcon(bd + "new_icon.bmp"));
    newImageButton->setToolTip("Create a blank image.");

    openButton->setIcon(QIcon(bd + "open_icon.bmp"));
    openButton->setToolTip("Load a new image from a file.");

    saveButton->setIcon(QIcon(bd + "save_icon.bmp"));
    saveButton->setToolTip("Save your drawing.");

    foregroundColorButton->setIcon(QIcon(bd + "fcolor_icon.bmp"));
    foregroundColorButton->setToolTip("Change the current pen color.");

    backgroundColorButton->setIcon(QIcon(bd + "bcolor_icon.bmp"));
    backgroundColorButton->setToolTip("Change the current background color.");

    undoButton->setIcon(QIcon(bd + "undo_icon.bmp"));
    undoButton->setToolTip("Undo last process.");

    redoButton->setIcon(QIcon(bd + "redo_icon.bmp"));
    redoButton->setToolTip("Redo last process.");

    clearImageButton->setIcon(QIcon(bd + "clearall_icon.bmp"));
    clearImageButton->setToolTip("Clear the screen.");

    penButton->setIcon(QIcon(bd + "pen_icon.bmp"));
    penButton->setToolTip("Pen Tool");
   // displayToolbarButton->setIcon(QIcon(bd + ""));
    eraserButton->setIcon(QIcon(bd + "eraser_icon.bmp"));
    eraserButton->setToolTip("Eraser.");

    rectangleButton->setIcon(QIcon(bd + "rect_icon.bmp"));
    rectangleButton->setToolTip("Add a rectangle.");

    lineButton->setIcon(QIcon(bd + "line_icon.bmp"));
    lineButton->setToolTip("Create a new line.");

    resizeButton->setIcon(QIcon(bd + "resize_icon.bmp"));
    resizeButton->setToolTip("Resize your image.");
}

void PaintWindow::connectButtons() {
    connect(newImageButton, SIGNAL(clicked()), this, SLOT(newImage()));
    connect(openButton, SIGNAL(clicked()), this, SLOT(open()));
    connect(saveButton, SIGNAL(clicked()), this, SLOT(saveAsBitmap()));
    connect(foregroundColorButton, SIGNAL(clicked()), this, SLOT(foregroundColor()));
    connect(backgroundColorButton, SIGNAL(clicked()), this, SLOT(backgroundColor()));
    connect(undoButton, SIGNAL(clicked()), this, SLOT(undo()));
    connect(redoButton, SIGNAL(clicked()), this, SLOT(redo()));
    connect(clearImageButton, SIGNAL(clicked()), this, SLOT(clearImage()));
    connect(penButton, SIGNAL(clicked()), this, SLOT(penTool()));
    connect(eraserButton, SIGNAL(clicked()), this, SLOT(erase()));
    connect(resizeButton, SIGNAL(clicked()), this, SLOT(resizeImage()));
    connect(lineButton, SIGNAL(clicked()), this, SLOT(line()));
    connect(rectangleButton, SIGNAL(clicked()), this, SLOT(rectangle()));
}


void PaintWindow::createIconMenuBar() {
    QToolBar* iconMenuBar = new QToolBar("Tool Bar", this);
    iconMenuBar->setContextMenuPolicy(Qt::PreventContextMenu);
    // get the buttons ready
    initiateButtons();
    // add the icons
    setButtonIcons();
    // connect the signals to slots for the buttons
    connectButtons();

    iconMenuBar->addWidget(newImageButton);
    iconMenuBar->addWidget(openButton);
    iconMenuBar->addWidget(saveButton);
    iconMenuBar->addWidget(foregroundColorButton);
    iconMenuBar->addWidget(backgroundColorButton);
    iconMenuBar->addWidget(undoButton);
    iconMenuBar->addWidget(redoButton);
    iconMenuBar->addWidget(clearImageButton);
    iconMenuBar->addWidget(penButton);
    iconMenuBar->addWidget(eraserButton);
    iconMenuBar->addWidget(rectangleButton);
    iconMenuBar->addWidget(lineButton);
    iconMenuBar->addWidget(resizeButton);
    addToolBarBreak();
    addToolBar(Qt::LeftToolBarArea, iconMenuBar);
    return;
}

bool PaintWindow::trySave() {
    // check for unsaved changes
    if (paintArea->isChanged()) {
        QMessageBox::StandardButton ret;
        ret = QMessageBox::warning(this, tr("Painter"),
                         tr("Your drawing has been modified.\n"
                            "Would you like to save your changes?"),
                         QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
       if (ret == QMessageBox::Save) {
           return saveDrawing("png");
       }
       else if (ret == QMessageBox::Cancel) {
           return false;
       }
    }
    return true;
}

bool PaintWindow::saveDrawing(const QByteArray &fileFormat) {
    QString currentPath = QDir::currentPath() + "/painter." + fileFormat;

    QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"), currentPath,
              tr("%1 Files (*.%2;;All Files (*)").arg(QString::fromLatin1(fileFormat.toUpper()))
                                                  .arg(QString::fromLatin1(fileFormat)));

    if (fileName.isEmpty()) {
        return false;
    } else {
        return paintArea->saveImage(fileName, fileFormat.constData());
    }
}





