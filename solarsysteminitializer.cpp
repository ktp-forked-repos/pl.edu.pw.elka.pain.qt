#include "solarsysteminitializer.h"
#include "planet.h"
#include "constants.h"

SolarSystemInitializer::SolarSystemInitializer(QObject *parent) : QObject(parent)
{

}

SolarSystem* SolarSystemInitializer::getSolarSystem()
{
    SolarSystem* system = new SolarSystem();
//    Planet* sun = new Planet(695700, 330000, 0, 0, 0, "Sun", system);
    //    Planet* mercury = new Planet(2.440, 0.06, 46.149340, 47.87, 0.33 * PI, "Mercury", system);
    //    Planet* venus = new Planet(6.052, 0.82, 108.939123, 35.02, 0.25 * PI, "Venus", system);
    //    Planet* earth = new Planet(6.378, 1, 147.879224, 29.78, 1.5 * PI, "Earth", system);
    //    Planet* mars = new Planet(3.396, 0.11, 207.339977, 24.08, 1.75*PI, "Mars", system);
    //    Planet* jupiter = new Planet(71.492, 317.8, 760.009880, 13.07, 1.4 * PI, "Jupiter", system);
    //    Planet* saturn = new Planet(60.268, 95.2, 1469.283824, 9.69, 1.66 * PI, "Saturn", system);
    //    Planet* uranus = new Planet(25.559, 14.6, 2998.745626, 6.81, 0.8 * PI, "Uranus", system);
    //    Planet* neptune = new Planet(24.764, 17.2, 4484.350139, 5.43, 0.4 * PI, "Neptune", system);

        Planet* sun = new Planet(695700, 330000, 0, 0, 0, "Sun", system);
            Planet* mercury = new Planet(2.440, 0.06, 46.149340, 2551, 0.33 * PI, "Mercury", system);
            Planet* venus = new Planet(6.052, 0.82, 108.939123, 1865, 0.25 * PI, "Venus", system);
            Planet* earth = new Planet(6.378, 1, 147.879224, 1600, 1.5 * PI, "Earth", system);
            Planet* mars = new Planet(3.396, 0.11, 207.339977, 1279, 1.75*PI, "Mars", system);
            Planet* jupiter = new Planet(71.492, 317.8, 760.009880, 697, 1.4 * PI, "Jupiter", system);
            Planet* saturn = new Planet(60.268, 95.2, 1469.283824, 516, 1.66 * PI, "Saturn", system);
            Planet* uranus = new Planet(25.559, 14.6, 2998.745626, 363, 0.8 * PI, "Uranus", system);
            Planet* neptune = new Planet(24.764, 17.2, 4484.350139, 289, 0.4 * PI, "Neptune", system);

    system->solarObjects.push_back(sun);
    system->solarObjects.push_back(mercury);
    system->solarObjects.push_back(venus);
    system->solarObjects.push_back(earth);
    system->solarObjects.push_back(mars);
    system->solarObjects.push_back(jupiter);
    system->solarObjects.push_back(saturn);
    system->solarObjects.push_back(uranus);
    system->solarObjects.push_back(neptune);
    return system;
}
