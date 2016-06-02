#ifndef GRAPICHSITEMS_H
#define GRAPICHSITEMS_H

#include <QGraphicsItem>
#include <QPainter>
#include <QDebug>   //might not be neseccery
#include <QObject>
#include <QMap>
#include <ctime>

const short WIDTH = 5;

class BaseFigure : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    QPen *pen;

    BaseFigure()
    {
        pen = new QPen(Qt::red);
        pen->setWidth(WIDTH);
    }

//public slots:
    //void setColor(Qt::GlobalColor col) { pen->setColor(col); }
};

class MySquare : public BaseFigure
{
    virtual QRectF boundingRect() const
    {
        return QRectF(0, 0, 200, 200);
    }

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {
        QRectF rec = boundingRect();

        painter->setPen(*pen);

        painter->drawRect(rec);
    }
};

class MyEllipse: public MySquare
{
public:
    QRectF boundingRect() const
    {
        return QRectF(/*50, 50, 200, 200*/);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {
        painter->setPen(*pen);

        painter->drawEllipse(boundingRect().center(), 100, 100);
    }
};

class MyTriangle: public MySquare
{
public:
    QRectF boundingRect() const
    {
        return QRectF(-100, -100, 200, 200);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {
        QPolygon polygon;
        polygon << QPoint(0, -75) << QPoint(120, 150) << QPoint (-120, 150);

        painter->setPen(*pen);

        painter->drawPolygon(polygon);
    }
};

class ColorRect : public QGraphicsRectItem
{
    QBrush *brush;

    QMap<int, Qt::GlobalColor> colorMap;

public:
    ColorRect()
    {
        brush = new QBrush(Qt::red);

        colorMap.insert(1, Qt::red);
        colorMap.insert(2, Qt::blue);
        colorMap.insert(3, Qt::green);
    }

    ColorRect* setCol()
    {
        QMap<int, Qt::GlobalColor>::iterator it = colorMap.find(rand() % 3 + 1);
        brush->setColor(it.value());

        return this;
    }

    virtual QRectF boundingRect() const
    {
        return QRectF(0, 0, 200, 200);
    }

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {
        QRectF rec = boundingRect();

        painter->setBrush(*brush);
        painter->drawRect(rec);
    }
};

#endif // GRAPICHSITEMS_H
