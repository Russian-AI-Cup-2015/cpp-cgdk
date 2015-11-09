#pragma once

#ifndef _GAME_H_
#define _GAME_H_

#include <vector>

namespace model {
    class Game {
    private:
        long long randomSeed;
        int tickCount;
        int worldWidth;
        int worldHeight;
        double trackTileSize;
        double trackTileMargin;
        int lapCount;
        int lapTickCount;
        int initialFreezeDurationTicks;
        double burningTimeDurationFactor;
        std::vector<int> finishTrackScores;
        int finishLapScore;
        double lapWaypointsSummaryScoreFactor;
        double carDamageScoreFactor;
        int carEliminationScore;
        double carWidth;
        double carHeight;
        double carEnginePowerChangePerTick;
        double carWheelTurnChangePerTick;
        double carAngularSpeedFactor;
        double carMovementAirFrictionFactor;
        double carRotationAirFrictionFactor;
        double carLengthwiseMovementFrictionFactor;
        double carCrosswiseMovementFrictionFactor;
        double carRotationFrictionFactor;
        int throwProjectileCooldownTicks;
        int useNitroCooldownTicks;
        int spillOilCooldownTicks;
        double nitroEnginePowerFactor;
        int nitroDurationTicks;
        int carReactivationTimeTicks;
        double buggyMass;
        double buggyEngineForwardPower;
        double buggyEngineRearPower;
        double jeepMass;
        double jeepEngineForwardPower;
        double jeepEngineRearPower;
        double bonusSize;
        double bonusMass;
        int pureScoreAmount;
        double washerRadius;
        double washerMass;
        double washerInitialSpeed;
        double washerDamage;
        double sideWasherAngle;
        double tireRadius;
        double tireMass;
        double tireInitialSpeed;
        double tireDamageFactor;
        double tireDisappearSpeedFactor;
        double oilSlickInitialRange;
        double oilSlickRadius;
        int oilSlickLifetime;
        int maxOiledStateDurationTicks;
    public:
        Game();
        Game(long long randomSeed, int tickCount, int worldWidth, int worldHeight, double trackTileSize,
                double trackTileMargin, int lapCount, int lapTickCount, int initialFreezeDurationTicks,
                double burningTimeDurationFactor, const std::vector<int>& finishTrackScores, int finishLapScore,
                double lapWaypointsSummaryScoreFactor, double carDamageScoreFactor, int carEliminationScore,
                double carWidth, double carHeight, double carEnginePowerChangePerTick, double carWheelTurnChangePerTick,
                double carAngularSpeedFactor, double carMovementAirFrictionFactor, double carRotationAirFrictionFactor,
                double carLengthwiseMovementFrictionFactor, double carCrosswiseMovementFrictionFactor,
                double carRotationFrictionFactor, int throwProjectileCooldownTicks, int useNitroCooldownTicks,
                int spillOilCooldownTicks, double nitroEnginePowerFactor, int nitroDurationTicks,
                int carReactivationTimeTicks, double buggyMass, double buggyEngineForwardPower,
                double buggyEngineRearPower, double jeepMass, double jeepEngineForwardPower, double jeepEngineRearPower,
                double bonusSize, double bonusMass, int pureScoreAmount, double washerRadius, double washerMass,
                double washerInitialSpeed, double washerDamage, double sideWasherAngle, double tireRadius,
                double tireMass, double tireInitialSpeed, double tireDamageFactor, double tireDisappearSpeedFactor,
                double oilSlickInitialRange, double oilSlickRadius, int oilSlickLifetime,
                int maxOiledStateDurationTicks);

        long long getRandomSeed() const;
        int getTickCount() const;
        int getWorldWidth() const;
        int getWorldHeight() const;
        double getTrackTileSize() const;
        double getTrackTileMargin() const;
        int getLapCount() const;
        int getLapTickCount() const;
        int getInitialFreezeDurationTicks() const;
        double getBurningTimeDurationFactor() const;
        const std::vector<int>& getFinishTrackScores() const;
        int getFinishLapScore() const;
        double getLapWaypointsSummaryScoreFactor() const;
        double getCarDamageScoreFactor() const;
        int getCarEliminationScore() const;
        double getCarWidth() const;
        double getCarHeight() const;
        double getCarEnginePowerChangePerTick() const;
        double getCarWheelTurnChangePerTick() const;
        double getCarAngularSpeedFactor() const;
        double getCarMovementAirFrictionFactor() const;
        double getCarRotationAirFrictionFactor() const;
        double getCarLengthwiseMovementFrictionFactor() const;
        double getCarCrosswiseMovementFrictionFactor() const;
        double getCarRotationFrictionFactor() const;
        int getThrowProjectileCooldownTicks() const;
        int getUseNitroCooldownTicks() const;
        int getSpillOilCooldownTicks() const;
        double getNitroEnginePowerFactor() const;
        int getNitroDurationTicks() const;
        int getCarReactivationTimeTicks() const;
        double getBuggyMass() const;
        double getBuggyEngineForwardPower() const;
        double getBuggyEngineRearPower() const;
        double getJeepMass() const;
        double getJeepEngineForwardPower() const;
        double getJeepEngineRearPower() const;
        double getBonusSize() const;
        double getBonusMass() const;
        int getPureScoreAmount() const;
        double getWasherRadius() const;
        double getWasherMass() const;
        double getWasherInitialSpeed() const;
        double getWasherDamage() const;
        double getSideWasherAngle() const;
        double getTireRadius() const;
        double getTireMass() const;
        double getTireInitialSpeed() const;
        double getTireDamageFactor() const;
        double getTireDisappearSpeedFactor() const;
        double getOilSlickInitialRange() const;
        double getOilSlickRadius() const;
        int getOilSlickLifetime() const;
        int getMaxOiledStateDurationTicks() const;
    };
}

#endif
