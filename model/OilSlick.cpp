#include "OilSlick.h"

using namespace model;

OilSlick::OilSlick()
        : CircularUnit(0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0), remainingLifetime(-1) { }

OilSlick::OilSlick(long long id, double mass, double x, double y, double speedX, double speedY, double angle,
        double angularSpeed, double radius, int remainingLifetime)
        : CircularUnit(id, mass, x, y, speedX, speedY, angle, angularSpeed, radius),
        remainingLifetime(remainingLifetime) { }

int OilSlick::getRemainingLifetime() const {
    return remainingLifetime;
}
