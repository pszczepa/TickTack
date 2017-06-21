#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>

#include <memory>

#include "gra.h"
#include "ai.hh"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Gra * wsk_gra, AI * wsk_ai ,QWidget *parent = 0);
    ~MainWindow();

private slots:

  void on_pushButton_1_clicked();
  void on_pushButton_2_clicked();
  void on_pushButton_3_clicked();
  void on_pushButton_4_clicked();
  void on_pushButton_5_clicked();
  void on_pushButton_6_clicked();
  void on_pushButton_7_clicked();
  void on_pushButton_8_clicked();
  void on_pushButton_9_clicked();


  void on_pushButton_clicked();

  void on_pushButton_10_clicked();

private:
    Ui::MainWindow *ui;

    Gra  * _gra;

    AI   * _ai;

    std::vector<std::shared_ptr<QLabel>>      v_labels;

    std::vector<std::shared_ptr<QPushButton>> v_buttons;

    void enableAll();

    void disableAll();

    bool ObslugaWygranej();

    void Odswiez(int);

    void Odswiez();

    void button_service(int const , int const, unsigned int button);

};

#endif // MAINWINDOW_H
