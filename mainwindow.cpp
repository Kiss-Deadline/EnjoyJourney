#include "mainwindow.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(QStringLiteral("Journey"));
    resize(500, 300);
}

MainWindow::~MainWindow()
{

}
