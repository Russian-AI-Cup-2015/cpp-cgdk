#pragma once

#ifndef _OIL_SLICK_H_
#define _OIL_SLICK_H_

#include "CircularUnit.h"

namespace model {
    class OilSlick : public CircularUnit {
    private:
        int remainingLifetime;
    public:
        OilSlick();
        OilSlick(long long id, double mass, double x, double y, double speedX, double speedY, double angle,
                double angularSpeed, double radius, int remainingLifetime);

        int getRemainingLifetime() const;
    };
}

#endif
