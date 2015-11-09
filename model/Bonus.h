#pragma once

#ifndef _BONUS_H_
#define _BONUS_H_

#include "BonusType.h"
#include "RectangularUnit.h"

namespace model {
    class Bonus : public RectangularUnit {
    private:
        BonusType type;
    public:
        Bonus();
        Bonus(long long id, double mass, double x, double y, double speedX, double speedY, double angle,
                double angularSpeed, double width, double height, BonusType type);

        BonusType getType() const;
    };
}

#endif
