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

    stimul = figures;

    //this is for scene state - to show stimul or not to show
    exists = false;

    scene = new QGraphicsScene(this);
    ellipse = new MyEllipse;
    triangle = new MyTriangle;
    square = new MySquare;

    figuresMap.insert(1, square);
    figuresMap.insert(2, ellipse);
    figuresMap.insert(3, triangle);

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
