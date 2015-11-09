#pragma once

#ifndef _WORLD_H_
#define _WORLD_H_

#include <string>
#include <vector>

#include "Bonus.h"
#include "Car.h"
#include "Direction.h"
#include "OilSlick.h"
#include "Player.h"
#include "Projectile.h"
#include "TileType.h"

namespace model {
    class World {
    private:
        int tick;
        int tickCount;
        int lastTickIndex;
        int width;
        int height;
        std::vector<Player> players;
        std::vector<Car> cars;
        std::vector<Projectile> projectiles;
        std::vector<Bonus> bonuses;
        std::vector<OilSlick> oilSlicks;
        std::string mapName;
        std::vector<std::vector<TileType> > tilesXY;
        std::vector<std::vector<int> > waypoints;
        Direction startingDirection;
    public:
        World();
        World(int tick, int tickCount, int lastTickIndex, int width, int height, const std::vector<Player>& players,
                const std::vector<Car>& cars, const std::vector<Projectile>& projectiles,
                const std::vector<Bonus>& bonuses, const std::vector<OilSlick>& oilSlicks, const std::string& mapName,
                const std::vector<std::vector<TileType> >& tilesXY, const std::vector<std::vector<int> >& waypoints,
                Direction startingDirection);

        int getTick() const;
        int getTickCount() const;
        int getLastTickIndex() const;
        int getWidth() const;
        int getHeight() const;
        const std::vector<Player>& getPlayers() const;
        const std::vector<Car>& getCars() const;
        const std::vector<Projectile>& getProjectiles() const;
        const std::vector<Bonus>& getBonuses() const;
        const std::vector<OilSlick>& getOilSlicks() const;
        const std::string& getMapName() const;
        const std::vector<std::vector<TileType> >& getTilesXY() const;
        const std::vector<std::vector<int> >& getWaypoints() const;
        Direction getStartingDirection() const;

        Player getMyPlayer() const;
    };
}

#endif
