#include "solarobject.h"
#include <QPainter>

SolarObject::SolarObject(double mass, QGraphicsItem *parent): QGraphicsItem(parent), mass(mass)
{

}



QRectF SolarObject::boundingRect() const Q_DECL_OVERRIDE
{
    return QRectF(-200, -200, 400, 400);
}

QPainterPath SolarObject::shape() const Q_DECL_OVERRIDE
{
    QPainterPath path;
    path.addEllipse(boundingRect());
    return path;
}

void SolarObject::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE
{
    static QColor color(200, 200, 200);
    painter->setBrush(color);
    painter->drawEllipse(boundingRect());
}

void SolarObject::advance(int step) Q_DECL_OVERRIDE
{
    x += vx;
    y += vy;
}
