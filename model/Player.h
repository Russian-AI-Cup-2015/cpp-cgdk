#pragma once

#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <string>

namespace model {
    class Player {
    private:
        long long id;
        bool me;
        std::string name;
        bool strategyCrashed;
        int score;
    public:
        Player();
        Player(long long id, bool me, const std::string& name, bool strategyCrashed, int score);

        long long getId() const;
        bool isMe() const;
        const std::string& getName() const;
        bool isStrategyCrashed() const;
        int getScore() const;
    };
}

#endif
