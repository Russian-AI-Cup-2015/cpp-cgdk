#include "PlayerContext.h"

using namespace model;
using namespace std;

PlayerContext::PlayerContext()
        : cars(vector<Car> ()), world(World ()) { }

PlayerContext::PlayerContext(const vector<Car>& cars, const World& world)
        : cars(cars), world(world) { }

const vector<Car>& PlayerContext::getCars() const {
    return cars;
}

const World& PlayerContext::getWorld() const {
    return world;
}
