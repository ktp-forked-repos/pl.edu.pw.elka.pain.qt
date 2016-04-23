#include "solarobject.h"

SolarObject::SolarObject(double mass, QGraphicsItem *parent): QGraphicsItem(parent), mass(mass)
{

}



QRectF SolarObject::boundingRect() const Q_DECL_OVERRIDE
{
    return QRectF()    ;
}

QPainterPath SolarObject::shape() const Q_DECL_OVERRIDE
{
    return QPainterPath();
}

void SolarObject::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE
{

}

void SolarObject::advance(int step) Q_DECL_OVERRIDE
{

}
