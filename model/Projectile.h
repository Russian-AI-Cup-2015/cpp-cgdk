#pragma once

#ifndef _PROJECTILE_H_
#define _PROJECTILE_H_

#include "CircularUnit.h"
#include "ProjectileType.h"

namespace model {
    class Projectile : public CircularUnit {
    private:
        long long carId;
        long long playerId;
        ProjectileType type;
    public:
        Projectile();
        Projectile(long long id, double mass, double x, double y, double speedX, double speedY, double angle,
                double angularSpeed, double radius, long long carId, long long playerId, ProjectileType type);

        long long getCarId() const;
        long long getPlayerId() const;
        ProjectileType getType() const;
    };
}

#endif
