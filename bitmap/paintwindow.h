#ifndef PAINTWINDOW_H
#define PAINTWINDOW_H

#include <qmainwindow.h>
#include <QContextMenuEvent>
#include "paintarea.h"
#include <QSlider>
#include <QToolButton>

class PaintWindow: public QMainWindow {

    Q_OBJECT

public:
    PaintWindow(QWidget* parent=0, const char* name=0);
    ~PaintWindow();

private:
    void createUndoView();
    void createActions();
    void createMenus();
    void createIconMenuBar();
    void initiateButtons();
    void setButtonIcons();
    void connectButtons();
    bool trySave();
    bool saveDrawing(const QByteArray &fileFormat);

    PaintArea  *paintArea;
    QSlider *slider;
    QMenu *saveAsMenu;
    QMenu *fileMenu;
    QMenu *optionMenu;
    QMenu *helpMenu;

    /* menu bar actions with icons */
    // load bitmap file
    QAction *openAct;
    // save current image;
    QList<QAction *> saveAsActs;
    QAction *changeBackgroundColor;
    // make the screen white
    QAction *clearScreenAct;
    // other
    QAction *exitAct;
    QAction *aboutAct;
    QAction *aboutQtAct;

    // menubar buttons
    QToolButton* newImageButton;
    QToolButton* openButton; // openAct
    QToolButton* saveButton;
    QToolButton* foregroundColorButton; // change pencolor
    QToolButton* backgroundColorButton;
    QToolButton* undoButton;
    QToolButton* redoButton;
    QToolButton* clearImageButton;
    //QToolButton* displayToolbarButton;
    QToolButton* penButton;
    QToolButton* eraserButton;
    QToolButton* rectangleButton;
    QToolButton* lineButton;
    QToolButton* resizeButton;

private slots:
    void save();
    // iconbar slots
    void newImage();
    void open();
    void saveAsBitmap();
    void foregroundColor();
    void backgroundColor();
    void undo();
    void redo();
    void clearImage();
    void penTool();
    void erase();
    void rectangle();
    void line();
    void resizeImage();
    // end iconBar slots
    void about();
    void setPenWidth(int newWidth);

    // add background color

protected:
    void closeEvent(QCloseEvent *event) override;
};

#endif // PAINTWINDOW_H
