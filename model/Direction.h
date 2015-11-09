#pragma once

#ifndef _DIRECTION_H_
#define _DIRECTION_H_

namespace model {
    enum Direction {
        _UNKNOWN_DIRECTION_ = -1,
        LEFT = 0,
        RIGHT = 1,
        UP = 2,
        DOWN = 3,
        _DIRECTION_COUNT_ = 4
    };
}

#endif
