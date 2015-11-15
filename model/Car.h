#pragma once

#ifndef _CAR_H_
#define _CAR_H_

#include "CarType.h"
#include "RectangularUnit.h"

namespace model {
    class Car : public RectangularUnit {
    private:
        long long playerId;
        int teammateIndex;
        bool teammate;
        CarType type;
        int projectileCount;
        int nitroChargeCount;
        int oilCanisterCount;
        int remainingProjectileCooldownTicks;
        int remainingNitroCooldownTicks;
        int remainingOilCooldownTicks;
        int remainingNitroTicks;
        int remainingOiledTicks;
        double durability;
        double enginePower;
        double wheelTurn;
        int nextWaypointIndex;
        int nextWaypointX;
        int nextWaypointY;
        bool finishedTrack;
    public:
        Car();
        Car(long long id, double mass, double x, double y, double speedX, double speedY, double angle,
                double angularSpeed, double width, double height, long long playerId, int teammateIndex, bool teammate,
                CarType type, int projectileCount, int nitroChargeCount, int oilCanisterCount,
                int remainingProjectileCooldownTicks, int remainingNitroCooldownTicks, int remainingOilCooldownTicks,
                int remainingNitroTicks, int remainingOiledTicks, double durability, double enginePower,
                double wheelTurn, int nextWaypointIndex, int nextWaypointX, int nextWaypointY, bool finishedTrack);

        long long getPlayerId() const;
        int getTeammateIndex() const;
        bool isTeammate() const;
        CarType getType() const;
        int getProjectileCount() const;
        int getNitroChargeCount() const;
        int getOilCanisterCount() const;
        int getRemainingProjectileCooldownTicks() const;
        int getRemainingNitroCooldownTicks() const;
        int getRemainingOilCooldownTicks() const;
        int getRemainingNitroTicks() const;
        int getRemainingOiledTicks() const;
        double getDurability() const;
        double getEnginePower() const;
        double getWheelTurn() const;
        int getNextWaypointIndex() const;
        int getNextWaypointX() const;
        int getNextWaypointY() const;
        bool isFinishedTrack() const;
    };
}

#endif
