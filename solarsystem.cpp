#include "solarsystem.h"
#include "rocket.h"

SolarSystem::SolarSystem(QObject *parent) : QObject(parent)
{
}


void SolarSystem::launchRocket(double v, double angle)
{
    Rocket* r = new Rocket(activePlanet, v, angle, this);
    solarObjects.push_back(r);
}


QRectF SolarSystem::boundingRect() const Q_DECL_OVERRIDE
{
    return QRectF(-3000, -3000, 6000, 6000)    ;
}

void SolarSystem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE
{

}

void SolarSystem::advance(int step) Q_DECL_OVERRIDE
{
    for(std::list<SolarObject*>::iterator it = solarObjects.begin();
        it != solarObjects.end(); ++it)
    {
        SolarObject* s = *it;
        s->setPos(s->x, s->y);
    }
}
