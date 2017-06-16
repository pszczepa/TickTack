#include "mainwindow.h"

#include <QApplication>
#include <QPicture>

#include <iostream>

#include "przyciski.h"
#include "gra.h"

int main(int argc, char *argv[])
{
    Gra          gra;

    AI           ai;

    QApplication a(argc, argv);

    MainWindow   w(&gra, &ai);



    w.show();

    return a.exec();
}
