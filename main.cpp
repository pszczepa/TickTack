#include "mainwindow.h"

#include <QApplication>
#include <QPicture>

#include "przyciski.h"
#include "gra.h"

int main(int argc, char *argv[])
{
    Gra          gra;

    QApplication a(argc, argv);

    MainWindow   w(&gra);



    w.show();

    return a.exec();
}
