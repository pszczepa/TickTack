#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "przyciski.h"
#include "gra.h"

#include <vector>


MainWindow::MainWindow(Gra * gra, AI * wsk_ai,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _gra(gra),
    _ai(wsk_ai)
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
  if(ui->radioLatwy->isChecked())
    {
        _ai->UstawPoziomTrudnosci(0);
    }
  else if(ui->radioSredni->isChecked())
    {
        _ai->UstawPoziomTrudnosci(1);
    }
  else
    {
        _ai->UstawPoziomTrudnosci(2);
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
  else if(ui->radioPvC->isChecked())// AI
    {
      std::cout<<"PVC"<<std::endl;
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

void MainWindow::disableAll()
{
  for(size_t i = 0; i < v_labels.size(); ++i)
    {
       v_labels.at(i)->setEnabled(false);
    }

  for(size_t i = 0; i < v_buttons.size(); ++i)
    {
       v_buttons.at(i)->setEnabled(false);
    }
}

void MainWindow::ObslugaWygranej()
{
  if(_gra->SprawdzCzyWygrana())
    {
      if(_gra->ZwrocWynik() == _gra->_KRZYZYK)
        {
          ui->label_wygrana->setText("Wygral Krzyżyk");

        }
      else if (_gra->ZwrocWynik() == _gra->_KOLKO)
        {
          ui->label_wygrana->setText("Wygralo Kółko");
        }

      ui->label_wygrana->setEnabled(true);

      _gra->ZakonczGre();
      disableAll();
    }
}

void MainWindow::Odswiez(int miejsce)
{
  QImage temp;

  if(!_gra->ZwrocTure())
  {
    temp = _gra->xReturn();
  }
  else
  {
    temp = _gra->oReturn();

  }

  v_buttons.at(miejsce)->setEnabled(false);
  v_labels.at(miejsce)->setPixmap(QPixmap::fromImage(temp));
}

void MainWindow::button_service(const int x, const int y, unsigned int button)
{
  int aiWpisano;

  if(!_gra->ZwrocKoniec())
  {
    _gra->Wypelnij(x,y);
    _gra->ZamienTure();
    Odswiez(button);

    ObslugaWygranej();

    if(!_gra->ZwrocPvC() && !_gra->ZwrocKoniec())
    {

      std::cout<<"Komputer mysli" << std::endl;
      aiWpisano =  _ai->WykonajRuch(_gra);
      _gra->ZamienTure();
      Odswiez(--aiWpisano);
      ObslugaWygranej();
    }



     _gra->DrukujPlansze();
    }
}
