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
    //template<class T> std::map<T, int> colors;

protected:

    enum Stimulus { figures, words, colors, combo };

    bool exists;
    QGraphicsItem *stimulusType;
    Stimulus stimul;

    QGraphicsScene *scene;
    MyEllipse *ellipse;
    MyTriangle *triangle;
    MySquare *square;

    void changeEvent(QEvent *e);
    template<class T> void blinc(T );

    Ui::TestBase *ui;
};

template<class T>
void TestBase::blinc(T stimul)
{
    static T prev = NULL;
    scene->removeItem(prev);

    scene->addItem(stimul);
    exists ? ui->graphicsView->setScene(scene) : ui->graphicsView->setScene(NULL);

    prev = stimul;
}

#endif // TESTBASE_H
