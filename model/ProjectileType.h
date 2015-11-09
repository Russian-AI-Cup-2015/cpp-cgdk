#pragma once

#ifndef _PROJECTILE_TYPE_H_
#define _PROJECTILE_TYPE_H_

namespace model {
    enum ProjectileType {
        _UNKNOWN_PROJECTILE_TYPE_ = -1,
        WASHER = 0,
        TIRE = 1,
        _PROJECTILE_TYPE_COUNT_ = 2
    };
}

#endif
