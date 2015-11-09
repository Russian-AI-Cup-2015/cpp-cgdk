#include "World.h"

using namespace model;
using namespace std;

World::World()
        : tick(-1), tickCount(-1), lastTickIndex(-1), width(-1), height(-1), players(vector<Player> ()),
        cars(vector<Car> ()), projectiles(vector<Projectile> ()), bonuses(vector<Bonus> ()),
        oilSlicks(vector<OilSlick> ()), mapName(""), tilesXY(vector<vector<TileType> > ()),
        waypoints(vector<vector<int> > ()), startingDirection(_UNKNOWN_DIRECTION_) { }

World::World(int tick, int tickCount, int lastTickIndex, int width, int height, const vector<Player>& players,
        const vector<Car>& cars, const vector<Projectile>& projectiles, const vector<Bonus>& bonuses,
        const vector<OilSlick>& oilSlicks, const string& mapName, const vector<vector<TileType> >& tilesXY,
        const vector<vector<int> >& waypoints, Direction startingDirection)
        : tick(tick), tickCount(tickCount), lastTickIndex(lastTickIndex), width(width), height(height),
        players(players), cars(cars), projectiles(projectiles), bonuses(bonuses), oilSlicks(oilSlicks),
        mapName(mapName), tilesXY(tilesXY), waypoints(waypoints), startingDirection(startingDirection) { }

int World::getTick() const {
    return tick;
}

int World::getTickCount() const {
    return tickCount;
}

int World::getLastTickIndex() const {
    return lastTickIndex;
}

int World::getWidth() const {
    return width;
}

int World::getHeight() const {
    return height;
}

const vector<Player>& World::getPlayers() const {
    return players;
}

const vector<Car>& World::getCars() const {
    return cars;
}

const vector<Projectile>& World::getProjectiles() const {
    return projectiles;
}

const vector<Bonus>& World::getBonuses() const {
    return bonuses;
}

const vector<OilSlick>& World::getOilSlicks() const {
    return oilSlicks;
}

const string& World::getMapName() const {
    return mapName;
}

const vector<vector<TileType> >& World::getTilesXY() const {
    return tilesXY;
}

const vector<vector<int> >& World::getWaypoints() const {
    return waypoints;
}

Direction World::getStartingDirection() const {
    return startingDirection;
}

Player World::getMyPlayer() const {
    for (int playerIndex = (int) players.size() - 1; playerIndex >= 0; --playerIndex) {
        Player player = players[playerIndex];
        if (player.isMe()) {
            return player;
        }
    }

    throw;
}
