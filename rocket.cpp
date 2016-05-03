#include "rocket.h"
#include <QtMath>
#include <QPainter>

Rocket::Rocket(Planet* startPlanet, double v,
               double angle, QGraphicsItem *parent) : SolarObject(ROCKET_MASS, parent)
{
    x = startPlanet->x + startPlanet->radius * cos(angle);
    y = startPlanet->y + startPlanet->radius * sin(angle);
    vx = v * cos(angle);
    vy = v * sin(angle);
}

QRectF Rocket::boundingRect() const Q_DECL_OVERRIDE
{
    return QRectF(-80, -80, 160, 160);
}

void Rocket::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE
{
    static QColor color(255, 0, 0);
    painter->setBrush(color);
    painter->drawEllipse(boundingRect());
}

QPainterPath Rocket::shape() const Q_DECL_OVERRIDE
{
    QPainterPath path;
    path.addEllipse(boundingRect());
    return path;
}
