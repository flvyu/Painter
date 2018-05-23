# Painter
For this program I implemented a version of the paint program.
The requirements I implemented include the following:
create, load, save, change background and foreground color, one level undo and redo,
clear, and I also implemented modifications of tools such as the pen tool,
eraser tool, line tool, and rectangle tool.

I added functionalities to a toolbal on the leftside of the window.
I also added a tool dialog for the pentool, line tool, eraser tool, and rectangle tool.

For sliders, I added a feaute to see the values as they changed, but this causes the labels to
be removed. Each tool has their own pen and changing one pen does not change the pen of
the other tool. For example, if the line tool width was changed to 20, the rectangle and
eraser tool width would still be the default size.

I also implemented mousePressevent, mouseReleaseevent, and mouseMoveEvent, but I did
not implement a mouseDoubleClick event.

I also implemented mouseRightClick to access the dialogs. To do this, just right click
on the canvas after choosing the tool you want.

OTHER:
This project was very time-consuming.
I used the scribble tutorial from QT to get started with the implementation.

The only thing not implemented is the drawtype.
