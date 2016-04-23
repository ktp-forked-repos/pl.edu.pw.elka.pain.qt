#ifndef SOLARSYSTEMINITIALIZER_H
#define SOLARSYSTEMINITIALIZER_H

#include <QObject>
#include "solarsystem.h"

class SolarSystemInitializer : public QObject
{
    Q_OBJECT
public:
    explicit SolarSystemInitializer(QObject *parent = 0);
    SolarSystem getSolarSystem();

signals:

public slots:
};

#endif // SOLARSYSTEMINITIALIZER_H
