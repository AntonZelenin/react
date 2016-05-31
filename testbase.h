#ifndef TESTBASE_H
#define TESTBASE_H

#include <QDialog>
#include <QtGui>
#include "grapichsItems.h"
#include <QMap>

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

    QMap<int, QGraphicsItem*> figures;
    QMap<int, QString> words;
    //template<class T> std::map<T, int> colors;

protected:

    enum Stimulus { figure, word, color, mix };

    bool exists;
    QGraphicsItem *stimulusType;
    Stimulus stimul;

    QGraphicsScene *scene;
    MyEllipse *ellipse;
    MyTriangle *triangle;
    MySquare *square;

    void changeEvent(QEvent *e);
    template<class T> void blinc(T );
    virtual void timerEvent(QTimerEvent *);

private:
    Ui::TestBase *ui;
};

#endif // TESTBASE_H
