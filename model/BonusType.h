#pragma once

#ifndef _BONUS_TYPE_H_
#define _BONUS_TYPE_H_

namespace model {
    enum BonusType {
        _UNKNOWN_BONUS_TYPE_ = -1,
        REPAIR_KIT = 0,
        AMMO_CRATE = 1,
        NITRO_BOOST = 2,
        OIL_CANISTER = 3,
        PURE_SCORE = 4,
        _BONUS_TYPE_COUNT_ = 5
    };
}

#endif
