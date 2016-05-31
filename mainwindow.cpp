#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include "pzmr.h"
#include <QString>
#include "rw_1_3.h"
#include "rw_2_3.h"
#include "ufp_np.h"
#include "snp.h"

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
      {
         PZMR pzmr;
         pzmr.showFullScreen();
         pzmr.startTimer(pzmr.getExpo());

         pzmr.exec();
      }
      break;
  case 1:
      {
         RW_1_3 rw13;
         rw13.showFullScreen();
         rw13.startTimer(rw13.getExpo());

         rw13.exec();
      }
      break;
  case 2:
      {
         RW_2_3 rw23;
         rw23.showFullScreen();
         rw23.startTimer(rw23.getExpo());

         rw23.exec();
       }
      break;
  }
}

void MainWindow::feedbackRegime()
{
    switch(ui->FeedbackComboBox->currentIndex())
    {
    case 0:
        {
            UFP_NP ufp_np;
            ufp_np.showFullScreen();
            ufp_np.startTimer(ufp_np.getExpo());

            ufp_np.exec();
        }
        break;
    case 1:
        {
            SNP snp;
            snp.showFullScreen();
            snp.startTimer(snp.getExpo());

            snp.exec();
        }
        break;
    }
}

void MainWindow::imposedRegime()
{
    switch(ui->imposedComboBox->currentIndex())
    {
    case 0:
        {

        }
        break;
    case 1:
        {

        }
        break;
    }
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
    case 4:

        break;
    }
}
