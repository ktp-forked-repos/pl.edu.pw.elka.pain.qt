#ifndef SOLAROBJECT_H
#define SOLAROBJECT_H

#include <QObject>

class SolarObject : public QObject
{
    Q_OBJECT
public:
    explicit SolarObject(double mass, QObject *parent = 0);

    /**
     * @brief mass mass of an object in kilograms multiplied by earth's mass
     * which is equal to 6.046 * 10^24kg
     */
    const double mass;
    /**
     * @brief x position of the object in horizontal axis in kilometers
     */
    double x;
    /**
     * @brief y position of the object in vertical axis in kilometers
     */
    double y;
    /**
     * @brief vx speed of the object in horizontal axis in kilometers per second
     */
    double vx;
    /**
     * @brief vy speed of the object in verical axis in kilometers per second
     */
    double vy;
signals:

public slots:
};

#endif // SOLAROBJECT_H
