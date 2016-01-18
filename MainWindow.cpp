#include "MainWindow.h"

#include <QMenuBar>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent, Qt::WindowFlags flags)
    : QMainWindow(parent, flags)
{
    setObjectName("MainWindow");
    setWindowTitle("cpp-qt-pyqt-py");

    setupMenuBar();
}

void MainWindow::setupMenuBar()
{
        testMenu = menuBar()->addMenu(tr("&Test"));

        QAction *action = testMenu->addAction(tr("&Go"));
        connect(action, SIGNAL(triggered()), this, SLOT(go()));

}

void MainWindow::letsGo()
{
    qDebug() << "go";
}
