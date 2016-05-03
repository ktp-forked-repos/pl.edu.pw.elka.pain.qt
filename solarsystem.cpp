#include "solarsystem.h"
#include "rocket.h"
#include<math.h>
#include"constants.h"

SolarSystem::SolarSystem(QObject *parent) : QObject(parent)
{
    GravityC = GravityCBase;
    timeStep = timeStepBase;
}


void SolarSystem::launchRocket(double v, double angle)
{
    Rocket* r = new Rocket(activePlanet, v, angle, this);
    solarObjects.push_back(r);
}


QRectF SolarSystem::boundingRect() const Q_DECL_OVERRIDE
{
    return QRectF(-3000, -3000, 6000, 6000);
}

void SolarSystem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE
{

}

void SolarSystem::advance(int step) Q_DECL_OVERRIDE
{
    if(step == 1)
    {
        setObjectsPos();
    }
    else
    {
        setObjectsVelocity();
    }
}


void SolarSystem::setObjectsPos()
{
    for(std::list<SolarObject*>::iterator it = solarObjects.begin();
        it != solarObjects.end(); ++it)
    {
        SolarObject* s = *it;
        s->x += (s->vx * timeStep / 1000000);
        s->y += (s->vy * timeStep / 1000000);
        s->setPos(s->x, s->y);
    }
}

void SolarSystem::setObjectsVelocity()
{
    std::list<std::pair<SolarObject*, SolarObject*> > pairs =
            getSolarObjectsPairs();
    for(std::list<std::pair<SolarObject*, SolarObject*> >::iterator it = pairs.begin();
        it != pairs.end(); ++it)
    {
        std::pair<SolarObject*, SolarObject*> pair = *it;
        SolarObject* first = pair.first;
        SolarObject* second = pair.second;
        double distance = getDistanceBetween(first, second);
        double force = GravityC * first->mass * second->mass
                / distance / distance / 6046;
        double angle = getAngleBetween(first, second);
        double dv1 = force / first->mass * timeStep;
        double dv2 = force / second->mass * timeStep;
        first->changeVelocity(dv1, angle);
        second->changeVelocity(dv2, angle + PI);
    }
}


std::list<std::pair<SolarObject*, SolarObject*> > SolarSystem::getSolarObjectsPairs()
{
    std::list<std::pair<SolarObject*, SolarObject*> > pairs;
    for(std::list<SolarObject*>::iterator it1 = solarObjects.begin();
        it1 != solarObjects.end(); ++it1)
    {
        std::list<SolarObject*>::iterator it2 = it1;
        it2++;
        for(;it2 != solarObjects.end(); ++it2)
        {
            pairs.push_back(std::make_pair(*it1, *it2));
        }
    }
    return pairs;
}

double SolarSystem::getDistanceBetween(SolarObject* s1, SolarObject* s2)
{
    double x = s2->x - s1->x;
    double y = s2->y - s1->y;
    double squered = x*x + y*y;
    return sqrt(squered);
}

double SolarSystem::getAngleBetween(SolarObject* s1, SolarObject* s2)
{
    double x = s2->x - s1->x;
    double y = s2->y - s1->y;
    return atan2(x, y);
}
