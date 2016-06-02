#ifndef TESTBASE_H
#define TESTBASE_H

#include <QDialog>
#include <QtGui>
#include "grapichsItems.h"
#include <QMap>
#include "ui_testbase.h"
#include <QString>

typedef unsigned short ushort;

namespace Ui {
    class TestBase;
}

class TestBase : public QDialog
{
    Q_OBJECT

public:
    enum STIMULUS { figures, words, colors, combo };

    explicit TestBase(QWidget *parent = 0);
    ~TestBase();
    bool isExists() { return exists; }

    QMap<int, QGraphicsItem*> figuresMap;
    QMap<int, QString> wordsMap;

protected:

    ushort signalsAmount;
    bool exists;
    QGraphicsItem *stimulusType;

    QGraphicsScene *scene;
    MyEllipse *ellipse;
    MyTriangle *triangle;
    MySquare *square;
    ColorRect *colRect;
    QGraphicsTextItem *wordsStimul;

    void changeEvent(QEvent *e);
    template<class T> void blinc(T );

    Ui::TestBase *ui;

public:
    void setAmount(short am) { this->signalsAmount = am; }
    STIMULUS stimul;
    void setStimul ( short val);
};

template<class T>
void TestBase::blinc(T signal)
{
    static T prev = NULL;
    scene->removeItem(prev);

    if(exists) scene->addItem(signal);
    exists ? ui->graphicsView->setScene(scene) : ui->graphicsView->setScene(NULL);

    prev = signal;
}

#endif // TESTBASE_H
