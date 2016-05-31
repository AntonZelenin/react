#ifndef GRAPICHSITEMS_H
#define GRAPICHSITEMS_H

#include <QGraphicsItem>
#include <QPainter>
#include <QDebug>   //might not be neseccery

class MySquare : public QGraphicsItem
{
public:
    QPen *pen;

    MySquare()
    {
        pen = new QPen(Qt::red);
        pen->setWidth(5);
    }

    QRectF boundingRect() const
    {
        return QRectF(100, 100, 200, 200);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {
        QRectF rec = boundingRect();

        painter->setPen(*pen);

        painter->drawRect(rec);
    }
};

class MyEllipse: public QGraphicsItem
{
public:
    QPen *pen;

    MyEllipse()
    {
        pen = new QPen(Qt::red);
        pen->setWidth(5);
    }

    QRectF boundingRect() const
    {
        return QRectF(50, 50, 200, 200);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {
        painter->setPen(*pen);

        painter->drawEllipse(QPoint(-50, -50), 100, 100);
    }
};

class MyTriangle: public QGraphicsItem
{
public:
    QPen *pen;

    MyTriangle()
    {
        pen = new QPen(Qt::red);
        pen->setWidth(5);
    }

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

#endif // GRAPICHSITEMS_H
