#ifndef ROCKET_H
#define ROCKET_H

#include <QObject>
#include "solarobject.h"
#include "planet.h"

class Rocket : public SolarObject
{
    Q_OBJECT
public:
    explicit Rocket(Planet* startPlanet, unsigned int v,
                    unsigned int angle, QObject *parent = 0);

signals:

public slots:

private:
    /**
     * @brief ROCKET_MASS rocket mass in kilograms
     */
    static const unsigned int ROCKET_MASS = 2000000;
};

#endif // ROCKET_H
