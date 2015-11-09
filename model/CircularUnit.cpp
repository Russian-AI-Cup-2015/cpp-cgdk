#include "CircularUnit.h"

using namespace model;

CircularUnit::CircularUnit(long long id, double mass, double x, double y, double speedX, double speedY, double angle,
        double angularSpeed, double radius)
        : Unit(id, mass, x, y, speedX, speedY, angle, angularSpeed), radius(radius) { }

double CircularUnit::getRadius() const {
    return radius;
}

CircularUnit::~CircularUnit() { }
