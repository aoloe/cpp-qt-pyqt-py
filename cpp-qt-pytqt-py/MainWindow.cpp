#include "MainWindow.h"

#include <QMenuBar>
#include <QDebug>

#include <stdio.h>

#undef slots // http://stackoverflow.com/questions/27045323/embedding-python-3-4-into-c-qt-application
#include <Python.h>
#define slots

MainWindow::MainWindow(QWidget *parent, Qt::WindowFlags flags)
    : QMainWindow(parent, flags)
{
    setObjectName("MainWindow");
    setWindowTitle("cpp-qt-pyqt-py");

    setupMenuBar();

    // PyObject* PyRun_File(FILE *fp, const char *filename, int start, PyObject *globals, PyObject *locals)
    // FILE* file = fopen("test.py","r");
    // PyRun_SimpleFile(file, "test.py");

    PyObject *obj = Py_BuildValue("s", "test.py");
    FILE *file = _Py_fopen_obj(obj, "r+");
    if(file != NULL) {
        PyRun_SimpleFile(file, "../python/test.py");
    } else {
        qDebug() << "file test.py not found (did you copy it in the build directory";
    }
}

void MainWindow::setupMenuBar()
{
        testMenu = menuBar()->addMenu(tr("&Test"));

        QAction *action = testMenu->addAction(tr("&Go"));
        connect(action, SIGNAL(triggered()), this, SLOT(letsGo()));

}

void MainWindow::letsGo()
{
    qDebug() << "go";
}
