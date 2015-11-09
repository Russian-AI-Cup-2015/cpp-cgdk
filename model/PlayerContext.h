#pragma once

#ifndef _PLAYER_CONTEXT_H_
#define _PLAYER_CONTEXT_H_

#include <vector>

#include "Car.h"
#include "World.h"

namespace model {
    class PlayerContext {
    private:
        std::vector<Car> cars;
        World world;
    public:
        PlayerContext();
        PlayerContext(const std::vector<Car>& cars, const World& world);

        const std::vector<Car>& getCars() const;
        const World& getWorld() const;
    };
}

#endif
