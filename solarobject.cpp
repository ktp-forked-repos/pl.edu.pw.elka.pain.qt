#include "solarobject.h"
#include <QPainter>
#include<math.h>

SolarObject::SolarObject(double mass, QGraphicsItem *parent): QGraphicsItem(parent), mass(mass)
{

}



QRectF SolarObject::boundingRect() const Q_DECL_OVERRIDE
{
    return QRectF(-80, -80, 160, 160);
}

QPainterPath SolarObject::shape() const Q_DECL_OVERRIDE
{
    QPainterPath path;
    path.addEllipse(boundingRect());
    return path;
}

void SolarObject::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE
{
    static QColor color(256, 256, 256);
    painter->setBrush(color);
    painter->drawEllipse(boundingRect());
}

void SolarObject::advance(int step) Q_DECL_OVERRIDE
{
}

void SolarObject::changeVelocity(double dv, double angle)
{
    vx += sin(angle) * dv;
    vy += cos(angle) * dv;
}
