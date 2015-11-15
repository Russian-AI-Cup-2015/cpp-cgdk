#include "Car.h"

using namespace model;

Car::Car()
        : RectangularUnit(0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0), playerId(-1), teammateIndex(-1),
        teammate(false), type(_UNKNOWN_CAR_TYPE_), projectileCount(-1), nitroChargeCount(-1), oilCanisterCount(-1),
        remainingProjectileCooldownTicks(-1), remainingNitroCooldownTicks(-1), remainingOilCooldownTicks(-1),
        remainingNitroTicks(-1), remainingOiledTicks(-1), durability(-1.0), enginePower(-1.0), wheelTurn(-1.0),
        nextWaypointIndex(-1), nextWaypointX(-1), nextWaypointY(-1), finishedTrack(false) { }

Car::Car(long long id, double mass, double x, double y, double speedX, double speedY, double angle, double angularSpeed,
        double width, double height, long long playerId, int teammateIndex, bool teammate, CarType type,
        int projectileCount, int nitroChargeCount, int oilCanisterCount, int remainingProjectileCooldownTicks,
        int remainingNitroCooldownTicks, int remainingOilCooldownTicks, int remainingNitroTicks,
        int remainingOiledTicks, double durability, double enginePower, double wheelTurn, int nextWaypointIndex,
        int nextWaypointX, int nextWaypointY, bool finishedTrack)
        : RectangularUnit(id, mass, x, y, speedX, speedY, angle, angularSpeed, width, height), playerId(playerId),
        teammateIndex(teammateIndex), teammate(teammate), type(type), projectileCount(projectileCount),
        nitroChargeCount(nitroChargeCount), oilCanisterCount(oilCanisterCount),
        remainingProjectileCooldownTicks(remainingProjectileCooldownTicks),
        remainingNitroCooldownTicks(remainingNitroCooldownTicks), remainingOilCooldownTicks(remainingOilCooldownTicks),
        remainingNitroTicks(remainingNitroTicks), remainingOiledTicks(remainingOiledTicks), durability(durability),
        enginePower(enginePower), wheelTurn(wheelTurn), nextWaypointIndex(nextWaypointIndex),
        nextWaypointX(nextWaypointX), nextWaypointY(nextWaypointY), finishedTrack(finishedTrack) { }

long long Car::getPlayerId() const {
    return playerId;
}

int Car::getTeammateIndex() const {
    return teammateIndex;
}

bool Car::isTeammate() const {
    return teammate;
}

CarType Car::getType() const {
    return type;
}

int Car::getProjectileCount() const {
    return projectileCount;
}

int Car::getNitroChargeCount() const {
    return nitroChargeCount;
}

int Car::getOilCanisterCount() const {
    return oilCanisterCount;
}

int Car::getRemainingProjectileCooldownTicks() const {
    return remainingProjectileCooldownTicks;
}

int Car::getRemainingNitroCooldownTicks() const {
    return remainingNitroCooldownTicks;
}

int Car::getRemainingOilCooldownTicks() const {
    return remainingOilCooldownTicks;
}

int Car::getRemainingNitroTicks() const {
    return remainingNitroTicks;
}

int Car::getRemainingOiledTicks() const {
    return remainingOiledTicks;
}

double Car::getDurability() const {
    return durability;
}

double Car::getEnginePower() const {
    return enginePower;
}

double Car::getWheelTurn() const {
    return wheelTurn;
}

int Car::getNextWaypointIndex() const {
    return nextWaypointIndex;
}

int Car::getNextWaypointX() const {
    return nextWaypointX;
}

int Car::getNextWaypointY() const {
    return nextWaypointY;
}

bool Car::isFinishedTrack() const {
    return finishedTrack;
}
