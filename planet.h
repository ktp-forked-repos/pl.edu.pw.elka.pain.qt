#ifndef PLANET_H
#define PLANET_H

#include <QObject>
#include <QString>
#include "solarobject.h"

class Planet : public SolarObject
{
    Q_OBJECT
public:
    /**
     * @brief Planet default constructor for the Planet
     * @param radius radius of the planet described in kilometers
     * @param mass mass multipled by earths mass = 6.046 * 10^24kg
     * @param distanceFromSun distance from sun in kilometers multiplied by 10^6
     * @param v velocity of the planet described in kilometers per second
     * @param angleToSun angle relative to sun, between 0 and and 2*PI
     * @param name
     * @param parent
     */
    explicit Planet(double radius, double mass, double distanceFromSun,
                    double v, double angleToSun, QString name, QGraphicsItem *parent = 0);

    /**
     * @brief radius radius of the planet in kilometers
     */
    const double radius;
    /**
     * @brief name name of the planet
     */
    const QString name;
protected:

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    QPainterPath shape() const Q_DECL_OVERRIDE;

signals:

public slots:
};

#endif // PLANET_H
