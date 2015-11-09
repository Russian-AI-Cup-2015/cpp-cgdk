#include "Bonus.h"

using namespace model;

Bonus::Bonus()
        : RectangularUnit(0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0), type(_UNKNOWN_BONUS_TYPE_) { }

Bonus::Bonus(long long id, double mass, double x, double y, double speedX, double speedY, double angle,
        double angularSpeed, double width, double height, BonusType type)
        : RectangularUnit(id, mass, x, y, speedX, speedY, angle, angularSpeed, width, height), type(type) { }

BonusType Bonus::getType() const {
    return type;
}
