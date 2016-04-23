#include "solarsysteminitializer.h"

SolarSystemInitializer::SolarSystemInitializer(QObject *parent) : QObject(parent)
{

}

SolarSystem SolarSystemInitializer::getSolarSystem()
{
    SolarSystem* system = new SolarSystem(this->parent());
    system->solarObjects.push_back(new SolarObject(this));
}
