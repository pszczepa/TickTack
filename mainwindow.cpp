#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "przyciski.h"
#include "gra.h"


MainWindow::MainWindow(Gra * gra, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _gra(gra)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_1_clicked()
{
  _gra->Wypelnij(0,0);
  ui->pushButton_1->setEnabled(false);
  ui->label->setPixmap();
}

void MainWindow::on_pushButton_2_clicked()
{
  _gra->Wypelnij(0,1);
  ui->pushButton_2->setEnabled(false);
}

void MainWindow::on_pushButton_3_clicked()
{
  _gra->Wypelnij(0,2);
  ui->pushButton_3->setEnabled(false);
}

void MainWindow::on_pushButton_4_clicked()
{
  _gra->Wypelnij(1,0);
  ui->pushButton_4->setEnabled(false);
}

void MainWindow::on_pushButton_5_clicked()
{
  _gra->Wypelnij(1,1);
  ui->pushButton_5->setEnabled(false);
}

void MainWindow::on_pushButton_6_clicked()
{
  _gra->Wypelnij(1,2);
  ui->pushButton_6->setEnabled(false);
}

void MainWindow::on_pushButton_7_clicked()
{
  _gra->Wypelnij(2,0);
  ui->pushButton_7->setEnabled(false);
}

void MainWindow::on_pushButton_8_clicked()
{
  _gra->Wypelnij(2,1);
  ui->pushButton_8->setEnabled(false);
}

void MainWindow::on_pushButton_9_clicked()
{
  _gra->Wypelnij(2,2);
  ui->pushButton_9->setEnabled(false);
}

void MainWindow::on_pushButton_clicked()
{
  if(ui->radioLatwy)
    {
        _gra->UstawPoziomTrudnosci(0);
    }
  else if(ui->radioSredni)
    {
        _gra->UstawPoziomTrudnosci(1);
    }
  else
    {
        _gra->UstawPoziomTrudnosci(2);
    }

  _gra->RozpocznijGre(true);
  ui->frame->setEnabled(true);
  ui->frame_2->setEnabled(false);
  ui->frame_3->setEnabled(false);
  ui->pushButton->setEnabled(false);

  enableAll();

}

void MainWindow::on_pushButton_10_clicked()
{
  if(ui->radioPvP->isChecked())
    {
      _gra->RozpocznijGre(false);
    }
  else // AI
    {
      _gra->RozpocznijGre(true);
      ui->frame_2->setEnabled(true);
    }

    ui->pushButton->setEnabled(true);
    ui->frame_3->setEnabled(false);
}

void MainWindow::enableAll()
{
  ui->pushButton_1->setEnabled(true);
  ui->pushButton_2->setEnabled(true);
  ui->pushButton_3->setEnabled(true);
  ui->pushButton_4->setEnabled(true);
  ui->pushButton_5->setEnabled(true);
  ui->pushButton_6->setEnabled(true);
  ui->pushButton_7->setEnabled(true);
  ui->pushButton_8->setEnabled(true);
  ui->pushButton_9->setEnabled(true);

  ui->label->setEnabled(true);
  ui->label_2->setEnabled(true);
  ui->label_3->setEnabled(true);
  ui->label_4->setEnabled(true);
  ui->label_5->setEnabled(true);
  ui->label_6->setEnabled(true);
  ui->label_7->setEnabled(true);
  ui->label_8->setEnabled(true);
  ui->label_9->setEnabled(true);
}
