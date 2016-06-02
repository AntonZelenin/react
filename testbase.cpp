#include "testbase.h"
#include "ui_testbase.h"
#include <utility>
#include<ctime>
#include "grapichsItems.h"
#include <QKeyEvent>

TestBase::TestBase(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TestBase)
{
    ui->setupUi(this);
    ui->graphicsView->setPalette(Qt::black);

    //this is for scene state - to show stimul or not to show
    exists = false;

    scene = new QGraphicsScene(this);
    ellipse = new MyEllipse;
    triangle = new MyTriangle;
    square = new MySquare;
    colRect = new ColorRect;
    wordsStimul = new QGraphicsTextItem;

    figuresMap.insert(1, square);
    figuresMap.insert(2, ellipse);
    figuresMap.insert(3, triangle);

    wordsMap.insert(1, "diploma");
    wordsMap.insert(2, "death");
    wordsMap.insert(3, "lack of time");
}

TestBase::~TestBase()
{
    delete ui;
}

void TestBase::setStimul (short val)
{
    switch(val)
    {
    case 1:
        this->stimul = figures;
        break;
    case 2:
        this->stimul = words;
        break;
    case 3:
        this->stimul = colors;
        break;
    case 4:
        this->stimul = combo;
        break;
    }
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
