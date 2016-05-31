#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include "pzmr.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::optimalRegime()
{
  switch(ui->OptimalComboBox->currentIndex())
  {
  case 0:
      PZMR pzmr;
      pzmr.showFullScreen();
      pzmr.startTimer(1000);

      pzmr.exec();
      break;
  }
}

void MainWindow::feedbackRegime()
{

}

void MainWindow::imposedRegime()
{

}

void MainWindow::on_pushButton_clicked()
{
    switch(ui->tabWidget->currentIndex())
    {
    case 0:
        optimalRegime();
        break;
    case 1:
        feedbackRegime();
        break;
    case 3:
        imposedRegime();
        break;
    }
}
