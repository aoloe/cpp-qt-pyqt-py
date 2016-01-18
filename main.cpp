#include<QApplication>

// #include <Python.h>
// #undef B0 // http://stackoverflow.com/questions/15078060/embedding-python-in-qt-5

#include "MainWindow.h"

int main(int argc, char *argv[])
{
    // Py_Initialize();

    QApplication app(argc, argv);
    MainWindow window;
    window.resize(800, 600);
    window.show();
    return app.exec();
}
