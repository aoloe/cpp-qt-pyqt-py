#include<QApplication>

#undef slots // http://stackoverflow.com/questions/27045323/embedding-python-3-4-into-c-qt-application
#include <Python.h>
#define slots
#undef B0 // http://stackoverflow.com/questions/15078060/embedding-python-in-qt-5

#include "MainWindow.h"

int main(int argc, char *argv[])
{
    Py_Initialize();

    QApplication app(argc, argv);
    MainWindow window;
    window.resize(800, 600);
    window.show();
    int result = app.exec();
    Py_Finalize();
    return result;
}
