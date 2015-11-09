#include "RectangularUnit.h"

using namespace model;

RectangularUnit::RectangularUnit(long long id, double mass, double x, double y, double speedX, double speedY,
        double angle, double angularSpeed, double width, double height)
        : Unit(id, mass, x, y, speedX, speedY, angle, angularSpeed), width(width), height(height) { }

double RectangularUnit::getWidth() const {
    return width;
}

double RectangularUnit::getHeight() const {
    return height;
}

RectangularUnit::~RectangularUnit() { }
