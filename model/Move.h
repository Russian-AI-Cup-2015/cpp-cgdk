#pragma once

#ifndef _MOVE_H_
#define _MOVE_H_

namespace model {
    class Move {
    private:
        double enginePower;
        bool brake;
        double wheelTurn;
        bool throwProjectile;
        bool useNitro;
        bool spillOil;
    public:
        Move();

        double getEnginePower() const;
        void setEnginePower(const double enginePower);
        bool isBrake() const;
        void setBrake(const bool brake);
        double getWheelTurn() const;
        void setWheelTurn(const double wheelTurn);
        bool isThrowProjectile() const;
        void setThrowProjectile(const bool throwProjectile);
        bool isUseNitro() const;
        void setUseNitro(const bool useNitro);
        bool isSpillOil() const;
        void setSpillOil(const bool spillOil);
    };
}

#endif
