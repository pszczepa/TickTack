#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "przyciski.h"
#include "gra.h"

#include <vector>


MainWindow::MainWindow(Gra * gra, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _gra(gra)
{
    ui->setupUi(this);

    std::shared_ptr<QLabel> ptr_label(ui->label);
    std::shared_ptr<QLabel> ptr_label2(ui->label_2);
    std::shared_ptr<QLabel> ptr_label3(ui->label_3);
    std::shared_ptr<QLabel> ptr_label4(ui->label_4);
    std::shared_ptr<QLabel> ptr_label5(ui->label_5);
    std::shared_ptr<QLabel> ptr_label6(ui->label_6);
    std::shared_ptr<QLabel> ptr_label7(ui->label_7);
    std::shared_ptr<QLabel> ptr_label8(ui->label_8);
    std::shared_ptr<QLabel> ptr_label9(ui->label_9);

    std::shared_ptr<QPushButton> ptr_button1(ui->pushButton_1);
    std::shared_ptr<QPushButton> ptr_button2(ui->pushButton_2);
    std::shared_ptr<QPushButton> ptr_button3(ui->pushButton_3);
    std::shared_ptr<QPushButton> ptr_button4(ui->pushButton_4);
    std::shared_ptr<QPushButton> ptr_button5(ui->pushButton_5);
    std::shared_ptr<QPushButton> ptr_button6(ui->pushButton_6);
    std::shared_ptr<QPushButton> ptr_button7(ui->pushButton_7);
    std::shared_ptr<QPushButton> ptr_button8(ui->pushButton_8);
    std::shared_ptr<QPushButton> ptr_button9(ui->pushButton_9);

    v_labels.push_back(ptr_label);
    v_labels.push_back(ptr_label2);
    v_labels.push_back(ptr_label3);
    v_labels.push_back(ptr_label4);
    v_labels.push_back(ptr_label5);
    v_labels.push_back(ptr_label6);
    v_labels.push_back(ptr_label7);
    v_labels.push_back(ptr_label8);
    v_labels.push_back(ptr_label9);

    v_buttons.push_back(ptr_button1);
    v_buttons.push_back(ptr_button2);
    v_buttons.push_back(ptr_button3);
    v_buttons.push_back(ptr_button4);
    v_buttons.push_back(ptr_button5);
    v_buttons.push_back(ptr_button6);
    v_buttons.push_back(ptr_button7);
    v_buttons.push_back(ptr_button8);
    v_buttons.push_back(ptr_button9);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_1_clicked()
{
  button_service(0,0,0);
}

void MainWindow::on_pushButton_2_clicked()
{
   button_service(0,1,1);
}

void MainWindow::on_pushButton_3_clicked()
{
   button_service(0,2,2);
}

void MainWindow::on_pushButton_4_clicked()
{
   button_service(1,0,3);
}

void MainWindow::on_pushButton_5_clicked()
{
   button_service(1,1,4);
}

void MainWindow::on_pushButton_6_clicked()
{
   button_service(1,2,5);
}

void MainWindow::on_pushButton_7_clicked()
{
   button_service(2,0,6);
}

void MainWindow::on_pushButton_8_clicked()
{
   button_service(2,1,7);
}

void MainWindow::on_pushButton_9_clicked()
{
  button_service(2,2,8);
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

void MainWindow::on_pushButton_10_clicked() //start
{
  if(ui->radioPvP->isChecked())
    {
      _gra->UstawPvC(false);
    }
  else // AI
    {
      _gra->UstawPvC(true);
      ui->frame_2->setEnabled(true);
    }

    ui->pushButton->setEnabled(true);
    ui->frame_3->setEnabled(false);

}

void MainWindow::enableAll()
{

  for(size_t i = 0; i < v_labels.size(); ++i)
    {
       v_labels.at(i)->setEnabled(true);
    }

  for(size_t i = 0; i < v_buttons.size(); ++i)
    {
       v_buttons.at(i)->setEnabled(true);
    }
}

void MainWindow::button_service(const int x, const int y, unsigned int button)
{
  QImage temp;

  if(_gra->ZwrocTure())
    {
      temp = _gra->oReturn();
    }
  else
    {
      temp = _gra->xReturn();
    }


    v_buttons.at(button)->setEnabled(false);
    v_labels.at(button)->setPixmap(QPixmap::fromImage(temp));

    _gra->Wypelnij(x,y);
    _gra->ZamienTure();

    if(_gra->SprawdzCzyWygrana())
      {
        ui->label_10->setText("Wygrana");
        //Wygrano, ktos, jescze nie wiadomo kto, i co dalej ??
      }

      _gra->DrukujPlansze();
}
