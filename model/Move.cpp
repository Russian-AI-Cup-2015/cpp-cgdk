#include "Move.h"

using namespace model;

Move::Move()
        : enginePower(0.0), brake(false), wheelTurn(0.0), throwProjectile(false), useNitro(false), spillOil(false) { }

double Move::getEnginePower() const {
    return enginePower;
}

void Move::setEnginePower(const double enginePower) {
    this->enginePower = enginePower;
}

bool Move::isBrake() const {
    return brake;
}

void Move::setBrake(const bool brake) {
    this->brake = brake;
}

double Move::getWheelTurn() const {
    return wheelTurn;
}

void Move::setWheelTurn(const double wheelTurn) {
    this->wheelTurn = wheelTurn;
}

bool Move::isThrowProjectile() const {
    return throwProjectile;
}

void Move::setThrowProjectile(const bool throwProjectile) {
    this->throwProjectile = throwProjectile;
}

bool Move::isUseNitro() const {
    return useNitro;
}

void Move::setUseNitro(const bool useNitro) {
    this->useNitro = useNitro;
}

bool Move::isSpillOil() const {
    return spillOil;
}

void Move::setSpillOil(const bool spillOil) {
    this->spillOil = spillOil;
}
