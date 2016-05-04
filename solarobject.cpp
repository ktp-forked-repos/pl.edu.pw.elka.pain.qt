#include "solarobject.h"
#include <QPainter>
#include<math.h>

SolarObject::SolarObject(double mass, QGraphicsItem *parent): QGraphicsItem(parent), mass(mass), isDestroyed(false)
{

}

void SolarObject::changeVelocity(double dv, double angle)
{
    vx += sin(angle) * dv;
    vy += cos(angle) * dv;
}

void SolarObject::advance(int step)
{
    static int temp = 200;
    if(temp-- > 0) return;
    if(step == 1)
    {
        return;
    }

    QList<QGraphicsItem*> list = this->collidingItems();
    for(QList<QGraphicsItem*>::iterator it = list.begin();
        it != list.end(); ++it)
    {
        SolarObject* s = dynamic_cast<SolarObject*>(*it);
        if(s)
        {
            if(s->mass < this->mass)
            {
                s->isDestroyed = true;
            }
            else
            {
                this->isDestroyed = true;
                return;
            }
        }
    }
}
