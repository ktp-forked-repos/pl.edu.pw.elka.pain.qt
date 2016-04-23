#ifndef PLANET_H
#define PLANET_H

#include <QObject>
#include "solarobject.h"

class Planet : public SolarObject
{
    Q_OBJECT
public:
    explicit Planet(unsigned int radius, unsigned int distanceFromSun,
                    unsigned int v, unsigned int angleToSun, QObject *parent = 0);

    /**
     * @brief radius radius of the planet
     */
    const unsigned int radius;

signals:

public slots:
};

#endif // PLANET_H
