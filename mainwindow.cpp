#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QString>
#include <QButtonGroup>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    groupOptStimul = new QButtonGroup;
    groupOptAmount = new QButtonGroup;
    groupOptPZMRexpo = new QButtonGroup;
    groupOptRW13expo = new QButtonGroup;
    groupOptRW23expo = new QButtonGroup;

    groupOptStimul->addButton(ui->rbOptimalFigures, 1);
    groupOptStimul->addButton(ui->rbOptimalWords, 2);
    groupOptStimul->addButton(ui->rbOptimalColor, 3);
    groupOptStimul->addButton(ui->rbOptimalCombo, 4);

    groupOptAmount->addButton(ui->rbOptimal30, 30);
    groupOptAmount->addButton(ui->rbOptimal50, 50);

    groupOptPZMRexpo->addButton(ui->rbPzmr700, 700);
    groupOptPZMRexpo->addButton(ui->rbPzmr900, 900);

    groupOptRW13expo->addButton(ui->rbRW13_700, 700);
    groupOptRW13expo->addButton(ui->rbRW13_900, 900);
    groupOptRW13expo->addButton(ui->rbRW13_1200, 1200);
    groupOptRW13expo->addButton(ui->rbRW13_1500, 1500);

    groupOptRW23expo->addButton(ui->rbRW23_700, 700);
    groupOptRW23expo->addButton(ui->rbRW23_900, 900);
    groupOptRW23expo->addButton(ui->rbRW23_1200, 1200);
    groupOptRW23expo->addButton(ui->rbRW23_1500, 1500);
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
         pzmr = new PZMR;

         pzmr->setExpo(this->groupOptPZMRexpo->checkedId());
         pzmr->setAmount(this->groupOptAmount->checkedId());
         pzmr->setStimul(this->groupOptStimul->checkedId());

         pzmr->showFullScreen();
         pzmr->startTimer(pzmr->getExpo());

         pzmr->exec();
         delete pzmr;
      }
      break;
  case 1:
      {
         rw13 = new RW_1_3;

         rw13->setExpo(this->groupOptRW13expo->checkedId());
         rw13->setAmount(this->groupOptAmount->checkedId());
         rw13->setStimul(this->groupOptStimul->checkedId());

         rw13->showFullScreen();
         rw13->startTimer(rw13->getExpo());

         rw13->exec();
      }
      break;
  case 2:
      {
         rw23 = new RW_2_3;

         rw23->setAmount(this->groupOptAmount->checkedId());
         rw23->setExpo(this->groupOptRW23expo->checkedId());
         rw23->setStimul(this->groupOptStimul->checkedId());

         rw23->showFullScreen();
         rw23->startTimer(rw23->getExpo());

         rw23->exec();
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
            ufp_np->startTimer(ufp_np->getExpo());

            ufp_np->exec();
        }
        break;
    case 1:
        {
            //SNP snp;
            snp->showFullScreen();
            snp->startTimer(snp->getExpo());

            snp->exec();
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

void MainWindow::on_pbStart_clicked()
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
