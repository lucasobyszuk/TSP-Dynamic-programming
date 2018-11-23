#include "mainwindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    MainWindow w;
    w.startWindow();
    w.setWindowTitle("Travel Salesman Problem Solver");
    w.show();
    
    return a.exec();
}
