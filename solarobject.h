#ifndef SOLAROBJECT_H
#define SOLAROBJECT_H

#include <QObject>
#include <QGraphicsItem>

class SolarObject : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit SolarObject(double mass, QGraphicsItem *parent = 0);

    /**
     * @brief mass mass of an object in kilograms multiplied by earth's mass
     * which is equal to 6.046 * 10^24kg
     */
    const double mass;
    /**
     * @brief x position of the object in horizontal axis in kilometers multipled by 10^6
     */
    double x;
    /**
     * @brief y position of the object in vertical axis in kilometers multipled by 10^6
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
    /**
     * @brief isDestroyed true if object should be deleted from scene
     */
    bool isDestroyed;

    /**
     * @brief changeVelocity changes object velocity
     * @param dv total change in velocity (km/s)
     * @param angle angle relative to velocity change
     */
    void changeVelocity(double dv, double angle);

protected:
    void advance(int step) Q_DECL_OVERRIDE;

signals:
public slots:
private:
    /**
     * @brief checkCollisionsAndDestroy
     * Checks if item is colliding with any other item and if it is is
     * destroys object with lesser mass
     */
    void destroyIfNeeded();
};

#endif // SOLAROBJECT_H
