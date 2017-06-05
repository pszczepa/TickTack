#include "mainwindow.h"
#include <QApplication>
#include <QPicture>
#include "przyciski.h"

int main(int argc, char *argv[])
{
    Przyciski p1;
    QApplication a(argc, argv);
    MainWindow w;

    w.show();



    return a.exec();
}
