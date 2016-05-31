#ifndef TESTBASE_H
#define TESTBASE_H

#include <QDialog>
#include <QtGui>
#include "grapichsItems.h"
#include <QMap>

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
    bool exists;

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
