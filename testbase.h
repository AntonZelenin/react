#ifndef TESTBASE_H
#define TESTBASE_H

#include <QDialog>
#include <QtGui>
#include "grapichsItems.h"
#include <QMap>
#include "ui_testbase.h"

typedef unsigned short ushort;

namespace Ui {
    class TestBase;
}

class TestBase : public QDialog
{
    Q_OBJECT

public:
    explicit TestBase(QWidget *parent = 0);
    ~TestBase();
    bool isExists() { return exists; }

    QMap<int, QGraphicsItem*> figuresMap;
    QMap<int, QString> wordsMap;

protected:

    enum STIMULUS { figures, words, colors, combo };

    bool exists;
    QGraphicsItem *stimulusType;
    STIMULUS stimul;

    //Graphics items for scene
    QGraphicsScene *scene;
    MyEllipse *ellipse;
    MyTriangle *triangle;
    MySquare *square;
    ColorRect *colRect;

    void changeEvent(QEvent *e);
    template<class T> void blinc(T );

    Ui::TestBase *ui;

signals:
    void changeColor(Qt::GlobalColor col);
};

template<class T>
void TestBase::blinc(T signal)
{
    static T prev = NULL;
    scene->removeItem(prev);

    scene->addItem(signal);
    exists ? ui->graphicsView->setScene(scene) : ui->graphicsView->setScene(NULL);

    prev = signal;
}

#endif // TESTBASE_H
