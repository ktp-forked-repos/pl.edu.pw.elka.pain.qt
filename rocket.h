#ifndef ROCKET_H
#define ROCKET_H

#include <QObject>
#include "solarobject.h"
#include "planet.h"

class Rocket : public SolarObject
{
    Q_OBJECT
public:
    explicit Rocket(Planet* startPlanet, double v,
                    double angle, QGraphicsItem *parent = 0);

signals:

public slots:

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;
    QRectF boundingRect() const Q_DECL_OVERRIDE;
    QPainterPath shape() const Q_DECL_OVERRIDE;

private:
    /**
     * @brief ROCKET_MASS rocket mass in kilograms multiplied by earth's mass
     * which is equal to 6.046 * 10^24kg
     */
    static const double ROCKET_MASS = 1.0e-18;
};

#endif // ROCKET_H
