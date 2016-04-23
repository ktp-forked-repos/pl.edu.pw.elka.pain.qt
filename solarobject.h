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

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    QPainterPath shape() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) Q_DECL_OVERRIDE;

protected:
    void advance(int step) Q_DECL_OVERRIDE;

signals:

public slots:
};

#endif // SOLAROBJECT_H
