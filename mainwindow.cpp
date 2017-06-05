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

    QImage o;
    QImage x;

    bool o_loading = o.load("o.jpg");
    bool x_loading = x.load("x.jpg");

    if(o_loading && x_loading)
      {
         ui->label_10->setText("OK");

        ui->label->setPixmap(QPixmap::fromImage(o));

        ui->label_4->setPixmap(QPixmap::fromImage(x));

        ui->label_2->setPixmap(QPixmap::fromImage(o));
        ui->label_5->setPixmap(QPixmap::fromImage(o));

        ui->label_3->setPixmap(QPixmap::fromImage(x));
        ui->label_4->setPixmap(QPixmap::fromImage(x));

        ui->label_6->setPixmap(QPixmap::fromImage(o));
        ui->label_7->setPixmap(QPixmap::fromImage(x));
        ui->label_8->setPixmap(QPixmap::fromImage(x));
      }
    else
      {
        ui->label_10->setText("Error - unabled to load image");
      }


    ui->label_10->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->pushButton->setEnabled(false);
}

