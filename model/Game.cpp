#include "Game.h"

using namespace model;
using namespace std;

Game::Game()
        : randomSeed(-1), tickCount(-1), worldWidth(-1), worldHeight(-1), trackTileSize(-1.0), trackTileMargin(-1.0),
        lapCount(-1), lapTickCount(-1), initialFreezeDurationTicks(-1), burningTimeDurationFactor(-1.0),
        finishTrackScores(vector<int> ()), finishLapScore(-1), lapWaypointsSummaryScoreFactor(-1.0),
        carDamageScoreFactor(-1.0), carEliminationScore(-1), carWidth(-1.0), carHeight(-1.0),
        carEnginePowerChangePerTick(-1.0), carWheelTurnChangePerTick(-1.0), carAngularSpeedFactor(-1.0),
        carMovementAirFrictionFactor(-1.0), carRotationAirFrictionFactor(-1.0),
        carLengthwiseMovementFrictionFactor(-1.0), carCrosswiseMovementFrictionFactor(-1.0),
        carRotationFrictionFactor(-1.0), throwProjectileCooldownTicks(-1), useNitroCooldownTicks(-1),
        spillOilCooldownTicks(-1), nitroEnginePowerFactor(-1.0), nitroDurationTicks(-1), carReactivationTimeTicks(-1),
        buggyMass(-1.0), buggyEngineForwardPower(-1.0), buggyEngineRearPower(-1.0), jeepMass(-1.0),
        jeepEngineForwardPower(-1.0), jeepEngineRearPower(-1.0), bonusSize(-1.0), bonusMass(-1.0), pureScoreAmount(-1),
        washerRadius(-1.0), washerMass(-1.0), washerInitialSpeed(-1.0), washerDamage(-1.0), sideWasherAngle(-1.0),
        tireRadius(-1.0), tireMass(-1.0), tireInitialSpeed(-1.0), tireDamageFactor(-1.0),
        tireDisappearSpeedFactor(-1.0), oilSlickInitialRange(-1.0), oilSlickRadius(-1.0), oilSlickLifetime(-1),
        maxOiledStateDurationTicks(-1) { }

Game::Game(long long randomSeed, int tickCount, int worldWidth, int worldHeight, double trackTileSize,
        double trackTileMargin, int lapCount, int lapTickCount, int initialFreezeDurationTicks,
        double burningTimeDurationFactor, const vector<int>& finishTrackScores, int finishLapScore,
        double lapWaypointsSummaryScoreFactor, double carDamageScoreFactor, int carEliminationScore, double carWidth,
        double carHeight, double carEnginePowerChangePerTick, double carWheelTurnChangePerTick,
        double carAngularSpeedFactor, double carMovementAirFrictionFactor, double carRotationAirFrictionFactor,
        double carLengthwiseMovementFrictionFactor, double carCrosswiseMovementFrictionFactor,
        double carRotationFrictionFactor, int throwProjectileCooldownTicks, int useNitroCooldownTicks,
        int spillOilCooldownTicks, double nitroEnginePowerFactor, int nitroDurationTicks, int carReactivationTimeTicks,
        double buggyMass, double buggyEngineForwardPower, double buggyEngineRearPower, double jeepMass,
        double jeepEngineForwardPower, double jeepEngineRearPower, double bonusSize, double bonusMass,
        int pureScoreAmount, double washerRadius, double washerMass, double washerInitialSpeed, double washerDamage,
        double sideWasherAngle, double tireRadius, double tireMass, double tireInitialSpeed, double tireDamageFactor,
        double tireDisappearSpeedFactor, double oilSlickInitialRange, double oilSlickRadius, int oilSlickLifetime,
        int maxOiledStateDurationTicks)
        : randomSeed(randomSeed), tickCount(tickCount), worldWidth(worldWidth), worldHeight(worldHeight),
        trackTileSize(trackTileSize), trackTileMargin(trackTileMargin), lapCount(lapCount), lapTickCount(lapTickCount),
        initialFreezeDurationTicks(initialFreezeDurationTicks), burningTimeDurationFactor(burningTimeDurationFactor),
        finishTrackScores(finishTrackScores), finishLapScore(finishLapScore),
        lapWaypointsSummaryScoreFactor(lapWaypointsSummaryScoreFactor), carDamageScoreFactor(carDamageScoreFactor),
        carEliminationScore(carEliminationScore), carWidth(carWidth), carHeight(carHeight),
        carEnginePowerChangePerTick(carEnginePowerChangePerTick), carWheelTurnChangePerTick(carWheelTurnChangePerTick),
        carAngularSpeedFactor(carAngularSpeedFactor), carMovementAirFrictionFactor(carMovementAirFrictionFactor),
        carRotationAirFrictionFactor(carRotationAirFrictionFactor),
        carLengthwiseMovementFrictionFactor(carLengthwiseMovementFrictionFactor),
        carCrosswiseMovementFrictionFactor(carCrosswiseMovementFrictionFactor),
        carRotationFrictionFactor(carRotationFrictionFactor),
        throwProjectileCooldownTicks(throwProjectileCooldownTicks), useNitroCooldownTicks(useNitroCooldownTicks),
        spillOilCooldownTicks(spillOilCooldownTicks), nitroEnginePowerFactor(nitroEnginePowerFactor),
        nitroDurationTicks(nitroDurationTicks), carReactivationTimeTicks(carReactivationTimeTicks),
        buggyMass(buggyMass), buggyEngineForwardPower(buggyEngineForwardPower),
        buggyEngineRearPower(buggyEngineRearPower), jeepMass(jeepMass), jeepEngineForwardPower(jeepEngineForwardPower),
        jeepEngineRearPower(jeepEngineRearPower), bonusSize(bonusSize), bonusMass(bonusMass),
        pureScoreAmount(pureScoreAmount), washerRadius(washerRadius), washerMass(washerMass),
        washerInitialSpeed(washerInitialSpeed), washerDamage(washerDamage), sideWasherAngle(sideWasherAngle),
        tireRadius(tireRadius), tireMass(tireMass), tireInitialSpeed(tireInitialSpeed),
        tireDamageFactor(tireDamageFactor), tireDisappearSpeedFactor(tireDisappearSpeedFactor),
        oilSlickInitialRange(oilSlickInitialRange), oilSlickRadius(oilSlickRadius), oilSlickLifetime(oilSlickLifetime),
        maxOiledStateDurationTicks(maxOiledStateDurationTicks) { }

long long Game::getRandomSeed() const {
    return randomSeed;
}

int Game::getTickCount() const {
    return tickCount;
}

int Game::getWorldWidth() const {
    return worldWidth;
}

int Game::getWorldHeight() const {
    return worldHeight;
}

double Game::getTrackTileSize() const {
    return trackTileSize;
}

double Game::getTrackTileMargin() const {
    return trackTileMargin;
}

int Game::getLapCount() const {
    return lapCount;
}

int Game::getLapTickCount() const {
    return lapTickCount;
}

int Game::getInitialFreezeDurationTicks() const {
    return initialFreezeDurationTicks;
}

double Game::getBurningTimeDurationFactor() const {
    return burningTimeDurationFactor;
}

const vector<int>& Game::getFinishTrackScores() const {
    return finishTrackScores;
}

int Game::getFinishLapScore() const {
    return finishLapScore;
}

double Game::getLapWaypointsSummaryScoreFactor() const {
    return lapWaypointsSummaryScoreFactor;
}

double Game::getCarDamageScoreFactor() const {
    return carDamageScoreFactor;
}

int Game::getCarEliminationScore() const {
    return carEliminationScore;
}

double Game::getCarWidth() const {
    return carWidth;
}

double Game::getCarHeight() const {
    return carHeight;
}

double Game::getCarEnginePowerChangePerTick() const {
    return carEnginePowerChangePerTick;
}

double Game::getCarWheelTurnChangePerTick() const {
    return carWheelTurnChangePerTick;
}

double Game::getCarAngularSpeedFactor() const {
    return carAngularSpeedFactor;
}

double Game::getCarMovementAirFrictionFactor() const {
    return carMovementAirFrictionFactor;
}

double Game::getCarRotationAirFrictionFactor() const {
    return carRotationAirFrictionFactor;
}

double Game::getCarLengthwiseMovementFrictionFactor() const {
    return carLengthwiseMovementFrictionFactor;
}

double Game::getCarCrosswiseMovementFrictionFactor() const {
    return carCrosswiseMovementFrictionFactor;
}

double Game::getCarRotationFrictionFactor() const {
    return carRotationFrictionFactor;
}

int Game::getThrowProjectileCooldownTicks() const {
    return throwProjectileCooldownTicks;
}

int Game::getUseNitroCooldownTicks() const {
    return useNitroCooldownTicks;
}

int Game::getSpillOilCooldownTicks() const {
    return spillOilCooldownTicks;
}

double Game::getNitroEnginePowerFactor() const {
    return nitroEnginePowerFactor;
}

int Game::getNitroDurationTicks() const {
    return nitroDurationTicks;
}

int Game::getCarReactivationTimeTicks() const {
    return carReactivationTimeTicks;
}

double Game::getBuggyMass() const {
    return buggyMass;
}

double Game::getBuggyEngineForwardPower() const {
    return buggyEngineForwardPower;
}

double Game::getBuggyEngineRearPower() const {
    return buggyEngineRearPower;
}

double Game::getJeepMass() const {
    return jeepMass;
}

double Game::getJeepEngineForwardPower() const {
    return jeepEngineForwardPower;
}

double Game::getJeepEngineRearPower() const {
    return jeepEngineRearPower;
}

double Game::getBonusSize() const {
    return bonusSize;
}

double Game::getBonusMass() const {
    return bonusMass;
}

int Game::getPureScoreAmount() const {
    return pureScoreAmount;
}

double Game::getWasherRadius() const {
    return washerRadius;
}

double Game::getWasherMass() const {
    return washerMass;
}

double Game::getWasherInitialSpeed() const {
    return washerInitialSpeed;
}

double Game::getWasherDamage() const {
    return washerDamage;
}

double Game::getSideWasherAngle() const {
    return sideWasherAngle;
}

double Game::getTireRadius() const {
    return tireRadius;
}

double Game::getTireMass() const {
    return tireMass;
}

double Game::getTireInitialSpeed() const {
    return tireInitialSpeed;
}

double Game::getTireDamageFactor() const {
    return tireDamageFactor;
}

double Game::getTireDisappearSpeedFactor() const {
    return tireDisappearSpeedFactor;
}

double Game::getOilSlickInitialRange() const {
    return oilSlickInitialRange;
}

double Game::getOilSlickRadius() const {
    return oilSlickRadius;
}

int Game::getOilSlickLifetime() const {
    return oilSlickLifetime;
}

int Game::getMaxOiledStateDurationTicks() const {
    return maxOiledStateDurationTicks;
}
