#pragma once

#ifndef _TILE_TYPE_H_
#define _TILE_TYPE_H_

namespace model {
    enum TileType {
        _UNKNOWN_TILE_TYPE_ = -1,
        EMPTY = 0,
        VERTICAL = 1,
        HORIZONTAL = 2,
        LEFT_TOP_CORNER = 3,
        RIGHT_TOP_CORNER = 4,
        LEFT_BOTTOM_CORNER = 5,
        RIGHT_BOTTOM_CORNER = 6,
        LEFT_HEADED_T = 7,
        RIGHT_HEADED_T = 8,
        TOP_HEADED_T = 9,
        BOTTOM_HEADED_T = 10,
        CROSSROADS = 11,
        UNKNOWN = 12,
        _TILE_TYPE_COUNT_ = 13
    };
}

#endif
