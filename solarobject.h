#ifndef SOLAROBJECT_H
#define SOLAROBJECT_H

#include <QObject>

class SolarObject : public QObject
{
    Q_OBJECT
public:
    explicit SolarObject(unsigned int mass, QObject *parent = 0);
    explicit SolarObject(unsigned int mass, unsigned int x, unsigned int y,
                         unsigned int vx, unsigned int vy, QObject *parent = 0);

    /**
     * @brief mass mass of an object in kilograms
     */
    const unsigned int mass;
    /**
     * @brief x position of the object in horizontal axis in kilometers
     */
    unsigned int x;
    /**
     * @brief y position of the object in vertical axis in kilometers
     */
    unsigned int y;
    /**
     * @brief vx speed of the object in horizontal axis in kilometers per second
     */
    unsigned int vx;
    /**
     * @brief vy speed of the object in verical axis in kilometers per second
     */
    unsigned int vy;
signals:

public slots:
};

#endif // SOLAROBJECT_H
