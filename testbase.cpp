#include "testbase.h"
#include "ui_testbase.h"
#include <utility>
#include<ctime>
#include "grapichsItems.h"

TestBase::TestBase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestBase)
{
    ui->setupUi(this);
    ui->graphicsView->setPalette(Qt::black);

    exists = false;
    scene = new QGraphicsScene(this);
    ellipse = new MyEllipse;
    triangle = new MyTriangle;
    square = new MySquare;

    figures.insert(1, square);
    figures.insert(2, ellipse);
    figures.insert(3, triangle);

//    words.insert(std::make_pair("diploma", 1));
//    words.insert(std::make_pair("death", 2));
//    words.insert(std::make_pair("time", 3));

//    colors.insert(std::make_pair(ellipse, 1));
//    colors.insert(std::make_pair(ellipse, 1));
//    colors.insert(std::make_pair(ellipse, 1));
}

TestBase::~TestBase()
{
    delete ui;
}

void TestBase::timerEvent(QTimerEvent *ev)
{
    killTimer(ev->timerId());
    exists = !exists;

    srand(time(NULL));
    int i = (rand() % 3 + 1);

    QMap<int, QGraphicsItem*>::iterator it = figures.find(i);    //should it be static?? No, but why?
    blinc(it.value());


    if(isExists())
        this->startTimer(1000);
    else
        this->startTimer(rand() % 1000 + 500);
}


template<class T>
void TestBase::blinc(T stimul)
{
    static T prev = NULL;
    scene->removeItem(prev);

    scene->addItem(stimul);
    exists ? ui->graphicsView->setScene(scene) : ui->graphicsView->setScene(NULL);

    prev = stimul;
}

void TestBase::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
