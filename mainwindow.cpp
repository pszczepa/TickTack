#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "przyciski.h"
#include <QPicture>
#include <QPixmap>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap q("o.jpg");

    ui->label_2->setPixmap(q);
    ui->label->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QPixmap mypix ("o.jpg");
    ui->label->setPixmap(mypix);
}
