#include "Projectile.h"

using namespace model;

Projectile::Projectile()
        : CircularUnit(0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0), carId(-1), playerId(-1),
        type(_UNKNOWN_PROJECTILE_TYPE_) { }

Projectile::Projectile(long long id, double mass, double x, double y, double speedX, double speedY, double angle,
        double angularSpeed, double radius, long long carId, long long playerId, ProjectileType type)
        : CircularUnit(id, mass, x, y, speedX, speedY, angle, angularSpeed, radius), carId(carId), playerId(playerId),
        type(type) { }

long long Projectile::getCarId() const {
    return carId;
}

long long Projectile::getPlayerId() const {
    return playerId;
}

ProjectileType Projectile::getType() const {
    return type;
}
