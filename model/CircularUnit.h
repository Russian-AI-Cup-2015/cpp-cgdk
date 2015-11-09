#pragma once

#ifndef _CIRCULAR_UNIT_H_
#define _CIRCULAR_UNIT_H_

#include "Unit.h"

namespace model {
    class CircularUnit : public Unit {
    private:
        double radius;
    protected:
        CircularUnit(long long id, double mass, double x, double y, double speedX, double speedY, double angle,
                double angularSpeed, double radius);
    public:
        double getRadius() const;

        virtual ~CircularUnit();
    };
}

#endif
