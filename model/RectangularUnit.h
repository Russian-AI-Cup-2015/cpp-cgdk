#pragma once

#ifndef _RECTANGULAR_UNIT_H_
#define _RECTANGULAR_UNIT_H_

#include "Unit.h"

namespace model {
    class RectangularUnit : public Unit {
    private:
        double width;
        double height;
    protected:
        RectangularUnit(long long id, double mass, double x, double y, double speedX, double speedY, double angle,
                double angularSpeed, double width, double height);
    public:
        double getWidth() const;
        double getHeight() const;

        virtual ~RectangularUnit();
    };
}

#endif
