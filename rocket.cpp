#include "rocket.h"
#include"constants.h"
#include <QtMath>
#include <QPainter>

Rocket::Rocket(Planet* startPlanet, double v,
               double angle, QGraphicsItem *parent) : SolarObject(ROCKET_MASS, parent)
{
    x = startPlanet->x + startPlanet->radius * 10 * cos(angle);
    y = startPlanet->y + startPlanet->radius * 10 * sin(angle);
    vx = v * cos(angle);
    vy = v * sin(angle);

    double size = 10e-4;
    path.addEllipse(-size, -size, size*2, size*2);
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
    return path;
}
