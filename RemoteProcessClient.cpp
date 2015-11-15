#include "RemoteProcessClient.h"

#include <algorithm>
#include <cstdlib>

using namespace model;
using namespace std;

const bool LITTLE_ENDIAN_BYTE_ORDER = true;
const int INTEGER_SIZE_BYTES = sizeof(int);
const int LONG_SIZE_BYTES = sizeof(long long);

RemoteProcessClient::RemoteProcessClient(string host, int port)
        : cachedBoolFlag(false), cachedBoolValue(false), mapName(""), tilesXY(vector<vector<TileType> > ()),
        waypoints(vector<vector<int> > ()), startingDirection(_DIRECTION_COUNT_) {
    socket.Initialize();
    socket.DisableNagleAlgoritm();

    if (!socket.Open((uint8*) host.c_str(), (int16) port)) {
        exit(10001);
    }
}

void RemoteProcessClient::writeTokenMessage(const string& token) {
    writeEnum<MessageType>(AUTHENTICATION_TOKEN);
    writeString(token);
}

int RemoteProcessClient::readTeamSizeMessage() {
    ensureMessageType(readEnum<MessageType>(), TEAM_SIZE);
    return readInt();
}

void RemoteProcessClient::writeProtocolVersionMessage() {
    writeEnum<MessageType>(PROTOCOL_VERSION);
    writeInt(2);
}

Game RemoteProcessClient::readGameContextMessage() {
    ensureMessageType(readEnum<MessageType>(), GAME_CONTEXT);
    return readGame();
}

PlayerContext* RemoteProcessClient::readPlayerContextMessage() {
    MessageType messageType = readEnum<MessageType>();
    if (messageType == GAME_OVER) {
        return NULL;
    }

    ensureMessageType(messageType, PLAYER_CONTEXT);

    if (!readBoolean()) {
        return NULL;
    }

    cachedBoolFlag = true;
    cachedBoolValue = true;

    PlayerContext* playerContext = new PlayerContext;
    *playerContext = readPlayerContext();
    return playerContext;
}

void RemoteProcessClient::writeMovesMessage(const vector<Move>& moves) {
    writeEnum<MessageType>(MOVES_MESSAGE);
    writeMoves(moves);
}

void RemoteProcessClient::close() {
    socket.Close();
}

Bonus RemoteProcessClient::readBonus() {
    if (!readBoolean()) {
        exit(20001);
    }

    long long id = readLong();
    double mass = readDouble();
    double x = readDouble();
    double y = readDouble();
    double speedX = readDouble();
    double speedY = readDouble();
    double angle = readDouble();
    double angularSpeed = readDouble();
    double width = readDouble();
    double height = readDouble();
    BonusType type = readEnum<BonusType>();

    return Bonus(id, mass, x, y, speedX, speedY, angle, angularSpeed, width, height, type);
}

void RemoteProcessClient::writeBonus(const Bonus& bonus) {
    writeBoolean(true);

    writeLong(bonus.getId());
    writeDouble(bonus.getMass());
    writeDouble(bonus.getX());
    writeDouble(bonus.getY());
    writeDouble(bonus.getSpeedX());
    writeDouble(bonus.getSpeedY());
    writeDouble(bonus.getAngle());
    writeDouble(bonus.getAngularSpeed());
    writeDouble(bonus.getWidth());
    writeDouble(bonus.getHeight());
    writeEnum<BonusType>(bonus.getType());
}

vector<Bonus> RemoteProcessClient::readBonuses() {
    int bonusCount = readInt();
    if (bonusCount < 0) {
        exit(20002);
    }

    vector<Bonus> bonuses;
    bonuses.reserve(bonusCount);

    for (int bonusIndex = 0; bonusIndex < bonusCount; ++bonusIndex) {
        bonuses.push_back(readBonus());
    }

    return bonuses;
}

void RemoteProcessClient::writeBonuses(const vector<Bonus>& bonuses) {
    int bonusCount = bonuses.size();
    writeInt(bonusCount);

    for (int bonusIndex = 0; bonusIndex < bonusCount; ++bonusIndex) {
        writeBonus(bonuses[bonusIndex]);
    }
}

Car RemoteProcessClient::readCar() {
    if (!readBoolean()) {
        exit(20003);
    }

    long long id = readLong();
    double mass = readDouble();
    double x = readDouble();
    double y = readDouble();
    double speedX = readDouble();
    double speedY = readDouble();
    double angle = readDouble();
    double angularSpeed = readDouble();
    double width = readDouble();
    double height = readDouble();
    long long playerId = readLong();
    int teammateIndex = readInt();
    bool teammate = readBoolean();
    CarType type = readEnum<CarType>();
    int projectileCount = readInt();
    int nitroChargeCount = readInt();
    int oilCanisterCount = readInt();
    int remainingProjectileCooldownTicks = readInt();
    int remainingNitroCooldownTicks = readInt();
    int remainingOilCooldownTicks = readInt();
    int remainingNitroTicks = readInt();
    int remainingOiledTicks = readInt();
    double durability = readDouble();
    double enginePower = readDouble();
    double wheelTurn = readDouble();
    int nextWaypointIndex = readInt();
    int nextWaypointX = readInt();
    int nextWaypointY = readInt();
    bool finishedTrack = readBoolean();

    return Car(id, mass, x, y, speedX, speedY, angle, angularSpeed, width, height, playerId, teammateIndex, teammate,
            type, projectileCount, nitroChargeCount, oilCanisterCount, remainingProjectileCooldownTicks,
            remainingNitroCooldownTicks, remainingOilCooldownTicks, remainingNitroTicks, remainingOiledTicks,
            durability, enginePower, wheelTurn, nextWaypointIndex, nextWaypointX, nextWaypointY, finishedTrack);
}

void RemoteProcessClient::writeCar(const Car& car) {
    writeBoolean(true);

    writeLong(car.getId());
    writeDouble(car.getMass());
    writeDouble(car.getX());
    writeDouble(car.getY());
    writeDouble(car.getSpeedX());
    writeDouble(car.getSpeedY());
    writeDouble(car.getAngle());
    writeDouble(car.getAngularSpeed());
    writeDouble(car.getWidth());
    writeDouble(car.getHeight());
    writeLong(car.getPlayerId());
    writeInt(car.getTeammateIndex());
    writeBoolean(car.isTeammate());
    writeEnum<CarType>(car.getType());
    writeInt(car.getProjectileCount());
    writeInt(car.getNitroChargeCount());
    writeInt(car.getOilCanisterCount());
    writeInt(car.getRemainingProjectileCooldownTicks());
    writeInt(car.getRemainingNitroCooldownTicks());
    writeInt(car.getRemainingOilCooldownTicks());
    writeInt(car.getRemainingNitroTicks());
    writeInt(car.getRemainingOiledTicks());
    writeDouble(car.getDurability());
    writeDouble(car.getEnginePower());
    writeDouble(car.getWheelTurn());
    writeInt(car.getNextWaypointIndex());
    writeInt(car.getNextWaypointX());
    writeInt(car.getNextWaypointY());
    writeBoolean(car.isFinishedTrack());
}

vector<Car> RemoteProcessClient::readCars() {
    int carCount = readInt();
    if (carCount < 0) {
        exit(20004);
    }

    vector<Car> cars;
    cars.reserve(carCount);

    for (int carIndex = 0; carIndex < carCount; ++carIndex) {
        cars.push_back(readCar());
    }

    return cars;
}

void RemoteProcessClient::writeCars(const vector<Car>& cars) {
    int carCount = cars.size();
    writeInt(carCount);

    for (int carIndex = 0; carIndex < carCount; ++carIndex) {
        writeCar(cars[carIndex]);
    }
}

Game RemoteProcessClient::readGame() {
    if (!readBoolean()) {
        exit(20005);
    }

    long long randomSeed = readLong();
    int tickCount = readInt();
    int worldWidth = readInt();
    int worldHeight = readInt();
    double trackTileSize = readDouble();
    double trackTileMargin = readDouble();
    int lapCount = readInt();
    int lapTickCount = readInt();
    int initialFreezeDurationTicks = readInt();
    double burningTimeDurationFactor = readDouble();
    std::vector<int> finishTrackScores = readIntArray();
    int finishLapScore = readInt();
    double lapWaypointsSummaryScoreFactor = readDouble();
    double carDamageScoreFactor = readDouble();
    int carEliminationScore = readInt();
    double carWidth = readDouble();
    double carHeight = readDouble();
    double carEnginePowerChangePerTick = readDouble();
    double carWheelTurnChangePerTick = readDouble();
    double carAngularSpeedFactor = readDouble();
    double carMovementAirFrictionFactor = readDouble();
    double carRotationAirFrictionFactor = readDouble();
    double carLengthwiseMovementFrictionFactor = readDouble();
    double carCrosswiseMovementFrictionFactor = readDouble();
    double carRotationFrictionFactor = readDouble();
    int throwProjectileCooldownTicks = readInt();
    int useNitroCooldownTicks = readInt();
    int spillOilCooldownTicks = readInt();
    double nitroEnginePowerFactor = readDouble();
    int nitroDurationTicks = readInt();
    int carReactivationTimeTicks = readInt();
    double buggyMass = readDouble();
    double buggyEngineForwardPower = readDouble();
    double buggyEngineRearPower = readDouble();
    double jeepMass = readDouble();
    double jeepEngineForwardPower = readDouble();
    double jeepEngineRearPower = readDouble();
    double bonusSize = readDouble();
    double bonusMass = readDouble();
    int pureScoreAmount = readInt();
    double washerRadius = readDouble();
    double washerMass = readDouble();
    double washerInitialSpeed = readDouble();
    double washerDamage = readDouble();
    double sideWasherAngle = readDouble();
    double tireRadius = readDouble();
    double tireMass = readDouble();
    double tireInitialSpeed = readDouble();
    double tireDamageFactor = readDouble();
    double tireDisappearSpeedFactor = readDouble();
    double oilSlickInitialRange = readDouble();
    double oilSlickRadius = readDouble();
    int oilSlickLifetime = readInt();
    int maxOiledStateDurationTicks = readInt();

    return Game(randomSeed, tickCount, worldWidth, worldHeight, trackTileSize, trackTileMargin, lapCount, lapTickCount,
            initialFreezeDurationTicks, burningTimeDurationFactor, finishTrackScores, finishLapScore,
            lapWaypointsSummaryScoreFactor, carDamageScoreFactor, carEliminationScore, carWidth, carHeight,
            carEnginePowerChangePerTick, carWheelTurnChangePerTick, carAngularSpeedFactor, carMovementAirFrictionFactor,
            carRotationAirFrictionFactor, carLengthwiseMovementFrictionFactor, carCrosswiseMovementFrictionFactor,
            carRotationFrictionFactor, throwProjectileCooldownTicks, useNitroCooldownTicks, spillOilCooldownTicks,
            nitroEnginePowerFactor, nitroDurationTicks, carReactivationTimeTicks, buggyMass, buggyEngineForwardPower,
            buggyEngineRearPower, jeepMass, jeepEngineForwardPower, jeepEngineRearPower, bonusSize, bonusMass,
            pureScoreAmount, washerRadius, washerMass, washerInitialSpeed, washerDamage, sideWasherAngle, tireRadius,
            tireMass, tireInitialSpeed, tireDamageFactor, tireDisappearSpeedFactor, oilSlickInitialRange,
            oilSlickRadius, oilSlickLifetime, maxOiledStateDurationTicks);
}

void RemoteProcessClient::writeGame(const Game& game) {
    writeBoolean(true);

    writeLong(game.getRandomSeed());
    writeInt(game.getTickCount());
    writeInt(game.getWorldWidth());
    writeInt(game.getWorldHeight());
    writeDouble(game.getTrackTileSize());
    writeDouble(game.getTrackTileMargin());
    writeInt(game.getLapCount());
    writeInt(game.getLapTickCount());
    writeInt(game.getInitialFreezeDurationTicks());
    writeDouble(game.getBurningTimeDurationFactor());
    writeIntArray(game.getFinishTrackScores());
    writeInt(game.getFinishLapScore());
    writeDouble(game.getLapWaypointsSummaryScoreFactor());
    writeDouble(game.getCarDamageScoreFactor());
    writeInt(game.getCarEliminationScore());
    writeDouble(game.getCarWidth());
    writeDouble(game.getCarHeight());
    writeDouble(game.getCarEnginePowerChangePerTick());
    writeDouble(game.getCarWheelTurnChangePerTick());
    writeDouble(game.getCarAngularSpeedFactor());
    writeDouble(game.getCarMovementAirFrictionFactor());
    writeDouble(game.getCarRotationAirFrictionFactor());
    writeDouble(game.getCarLengthwiseMovementFrictionFactor());
    writeDouble(game.getCarCrosswiseMovementFrictionFactor());
    writeDouble(game.getCarRotationFrictionFactor());
    writeInt(game.getThrowProjectileCooldownTicks());
    writeInt(game.getUseNitroCooldownTicks());
    writeInt(game.getSpillOilCooldownTicks());
    writeDouble(game.getNitroEnginePowerFactor());
    writeInt(game.getNitroDurationTicks());
    writeInt(game.getCarReactivationTimeTicks());
    writeDouble(game.getBuggyMass());
    writeDouble(game.getBuggyEngineForwardPower());
    writeDouble(game.getBuggyEngineRearPower());
    writeDouble(game.getJeepMass());
    writeDouble(game.getJeepEngineForwardPower());
    writeDouble(game.getJeepEngineRearPower());
    writeDouble(game.getBonusSize());
    writeDouble(game.getBonusMass());
    writeInt(game.getPureScoreAmount());
    writeDouble(game.getWasherRadius());
    writeDouble(game.getWasherMass());
    writeDouble(game.getWasherInitialSpeed());
    writeDouble(game.getWasherDamage());
    writeDouble(game.getSideWasherAngle());
    writeDouble(game.getTireRadius());
    writeDouble(game.getTireMass());
    writeDouble(game.getTireInitialSpeed());
    writeDouble(game.getTireDamageFactor());
    writeDouble(game.getTireDisappearSpeedFactor());
    writeDouble(game.getOilSlickInitialRange());
    writeDouble(game.getOilSlickRadius());
    writeInt(game.getOilSlickLifetime());
    writeInt(game.getMaxOiledStateDurationTicks());
}

vector<Game> RemoteProcessClient::readGames() {
    int gameCount = readInt();
    if (gameCount < 0) {
        exit(20006);
    }

    vector<Game> games;
    games.reserve(gameCount);

    for (int gameIndex = 0; gameIndex < gameCount; ++gameIndex) {
        games.push_back(readGame());
    }

    return games;
}

void RemoteProcessClient::writeGames(const vector<Game>& games) {
    int gameCount = games.size();
    writeInt(gameCount);

    for (int gameIndex = 0; gameIndex < gameCount; ++gameIndex) {
        writeGame(games[gameIndex]);
    }
}

Move RemoteProcessClient::readMove() {
    if (!readBoolean()) {
        exit(20007);
    }

    Move move;

    move.setEnginePower(readDouble());
    move.setBrake(readBoolean());
    move.setWheelTurn(readDouble());
    move.setThrowProjectile(readBoolean());
    move.setUseNitro(readBoolean());
    move.setSpillOil(readBoolean());

    return move;
}

void RemoteProcessClient::writeMove(const Move& move) {
    writeBoolean(true);

    writeDouble(move.getEnginePower());
    writeBoolean(move.isBrake());
    writeDouble(move.getWheelTurn());
    writeBoolean(move.isThrowProjectile());
    writeBoolean(move.isUseNitro());
    writeBoolean(move.isSpillOil());
}

vector<Move> RemoteProcessClient::readMoves() {
    int moveCount = readInt();
    if (moveCount < 0) {
        exit(20008);
    }

    vector<Move> moves;
    moves.reserve(moveCount);

    for (int moveIndex = 0; moveIndex < moveCount; ++moveIndex) {
        moves.push_back(readMove());
    }

    return moves;
}

void RemoteProcessClient::writeMoves(const vector<Move>& moves) {
    int moveCount = moves.size();
    writeInt(moveCount);

    for (int moveIndex = 0; moveIndex < moveCount; ++moveIndex) {
        writeMove(moves[moveIndex]);
    }
}

OilSlick RemoteProcessClient::readOilSlick() {
    if (!readBoolean()) {
        exit(20009);
    }

    long long id = readLong();
    double mass = readDouble();
    double x = readDouble();
    double y = readDouble();
    double speedX = readDouble();
    double speedY = readDouble();
    double angle = readDouble();
    double angularSpeed = readDouble();
    double radius = readDouble();
    int remainingLifetime = readInt();

    return OilSlick(id, mass, x, y, speedX, speedY, angle, angularSpeed, radius, remainingLifetime);
}

void RemoteProcessClient::writeOilSlick(const OilSlick& oilSlick) {
    writeBoolean(true);

    writeLong(oilSlick.getId());
    writeDouble(oilSlick.getMass());
    writeDouble(oilSlick.getX());
    writeDouble(oilSlick.getY());
    writeDouble(oilSlick.getSpeedX());
    writeDouble(oilSlick.getSpeedY());
    writeDouble(oilSlick.getAngle());
    writeDouble(oilSlick.getAngularSpeed());
    writeDouble(oilSlick.getRadius());
    writeInt(oilSlick.getRemainingLifetime());
}

vector<OilSlick> RemoteProcessClient::readOilSlicks() {
    int oilSlickCount = readInt();
    if (oilSlickCount < 0) {
        exit(20010);
    }

    vector<OilSlick> oilSlicks;
    oilSlicks.reserve(oilSlickCount);

    for (int oilSlickIndex = 0; oilSlickIndex < oilSlickCount; ++oilSlickIndex) {
        oilSlicks.push_back(readOilSlick());
    }

    return oilSlicks;
}

void RemoteProcessClient::writeOilSlicks(const vector<OilSlick>& oilSlicks) {
    int oilSlickCount = oilSlicks.size();
    writeInt(oilSlickCount);

    for (int oilSlickIndex = 0; oilSlickIndex < oilSlickCount; ++oilSlickIndex) {
        writeOilSlick(oilSlicks[oilSlickIndex]);
    }
}

Player RemoteProcessClient::readPlayer() {
    if (!readBoolean()) {
        exit(20011);
    }

    long long id = readLong();
    bool me = readBoolean();
    std::string name = readString();
    bool strategyCrashed = readBoolean();
    int score = readInt();

    return Player(id, me, name, strategyCrashed, score);
}

void RemoteProcessClient::writePlayer(const Player& player) {
    writeBoolean(true);

    writeLong(player.getId());
    writeBoolean(player.isMe());
    writeString(player.getName());
    writeBoolean(player.isStrategyCrashed());
    writeInt(player.getScore());
}

vector<Player> RemoteProcessClient::readPlayers() {
    int playerCount = readInt();
    if (playerCount < 0) {
        exit(20012);
    }

    vector<Player> players;
    players.reserve(playerCount);

    for (int playerIndex = 0; playerIndex < playerCount; ++playerIndex) {
        players.push_back(readPlayer());
    }

    return players;
}

void RemoteProcessClient::writePlayers(const vector<Player>& players) {
    int playerCount = players.size();
    writeInt(playerCount);

    for (int playerIndex = 0; playerIndex < playerCount; ++playerIndex) {
        writePlayer(players[playerIndex]);
    }
}

PlayerContext RemoteProcessClient::readPlayerContext() {
    if (!readBoolean()) {
        exit(20013);
    }

    std::vector<Car> cars = readCars();
    World world = readWorld();

    return PlayerContext(cars, world);
}

void RemoteProcessClient::writePlayerContext(const PlayerContext& playerContext) {
    writeBoolean(true);

    writeCars(playerContext.getCars());
    writeWorld(playerContext.getWorld());
}

vector<PlayerContext> RemoteProcessClient::readPlayerContexts() {
    int playerContextCount = readInt();
    if (playerContextCount < 0) {
        exit(20014);
    }

    vector<PlayerContext> playerContexts;
    playerContexts.reserve(playerContextCount);

    for (int playerContextIndex = 0; playerContextIndex < playerContextCount; ++playerContextIndex) {
        playerContexts.push_back(readPlayerContext());
    }

    return playerContexts;
}

void RemoteProcessClient::writePlayerContexts(const vector<PlayerContext>& playerContexts) {
    int playerContextCount = playerContexts.size();
    writeInt(playerContextCount);

    for (int playerContextIndex = 0; playerContextIndex < playerContextCount; ++playerContextIndex) {
        writePlayerContext(playerContexts[playerContextIndex]);
    }
}

Projectile RemoteProcessClient::readProjectile() {
    if (!readBoolean()) {
        exit(20015);
    }

    long long id = readLong();
    double mass = readDouble();
    double x = readDouble();
    double y = readDouble();
    double speedX = readDouble();
    double speedY = readDouble();
    double angle = readDouble();
    double angularSpeed = readDouble();
    double radius = readDouble();
    long long carId = readLong();
    long long playerId = readLong();
    ProjectileType type = readEnum<ProjectileType>();

    return Projectile(id, mass, x, y, speedX, speedY, angle, angularSpeed, radius, carId, playerId, type);
}

void RemoteProcessClient::writeProjectile(const Projectile& projectile) {
    writeBoolean(true);

    writeLong(projectile.getId());
    writeDouble(projectile.getMass());
    writeDouble(projectile.getX());
    writeDouble(projectile.getY());
    writeDouble(projectile.getSpeedX());
    writeDouble(projectile.getSpeedY());
    writeDouble(projectile.getAngle());
    writeDouble(projectile.getAngularSpeed());
    writeDouble(projectile.getRadius());
    writeLong(projectile.getCarId());
    writeLong(projectile.getPlayerId());
    writeEnum<ProjectileType>(projectile.getType());
}

vector<Projectile> RemoteProcessClient::readProjectiles() {
    int projectileCount = readInt();
    if (projectileCount < 0) {
        exit(20016);
    }

    vector<Projectile> projectiles;
    projectiles.reserve(projectileCount);

    for (int projectileIndex = 0; projectileIndex < projectileCount; ++projectileIndex) {
        projectiles.push_back(readProjectile());
    }

    return projectiles;
}

void RemoteProcessClient::writeProjectiles(const vector<Projectile>& projectiles) {
    int projectileCount = projectiles.size();
    writeInt(projectileCount);

    for (int projectileIndex = 0; projectileIndex < projectileCount; ++projectileIndex) {
        writeProjectile(projectiles[projectileIndex]);
    }
}

World RemoteProcessClient::readWorld() {
    if (!readBoolean()) {
        exit(20017);
    }

    int tick = readInt();
    int tickCount = readInt();
    int lastTickIndex = readInt();
    int width = readInt();
    int height = readInt();
    std::vector<Player> players = readPlayers();
    std::vector<Car> cars = readCars();
    std::vector<Projectile> projectiles = readProjectiles();
    std::vector<Bonus> bonuses = readBonuses();
    std::vector<OilSlick> oilSlicks = readOilSlicks();

    if (mapName == "") {
        mapName = readString();
    }

    vector<vector<model::TileType> > newTilesXY = readEnumArray2D<TileType>();

    if (!newTilesXY.empty()) {
        tilesXY = newTilesXY;
    }

    if (waypoints.empty()) {
        waypoints = readIntArray2D();
    }

    if (startingDirection == _DIRECTION_COUNT_) {
        startingDirection = readEnum<Direction>();
    }

    return World(tick, tickCount, lastTickIndex, width, height, players, cars, projectiles, bonuses, oilSlicks, mapName,
            tilesXY, waypoints, startingDirection);
}

void RemoteProcessClient::writeWorld(const World& world) {
    writeBoolean(true);

    writeInt(world.getTick());
    writeInt(world.getTickCount());
    writeInt(world.getLastTickIndex());
    writeInt(world.getWidth());
    writeInt(world.getHeight());
    writePlayers(world.getPlayers());
    writeCars(world.getCars());
    writeProjectiles(world.getProjectiles());
    writeBonuses(world.getBonuses());
    writeOilSlicks(world.getOilSlicks());
    writeString(world.getMapName());
    writeEnumArray2D<TileType>(world.getTilesXY());
    writeIntArray2D(world.getWaypoints());
    writeEnum<Direction>(world.getStartingDirection());
}

vector<World> RemoteProcessClient::readWorlds() {
    int worldCount = readInt();
    if (worldCount < 0) {
        exit(20018);
    }

    vector<World> worlds;
    worlds.reserve(worldCount);

    for (int worldIndex = 0; worldIndex < worldCount; ++worldIndex) {
        worlds.push_back(readWorld());
    }

    return worlds;
}

void RemoteProcessClient::writeWorlds(const vector<World>& worlds) {
    int worldCount = worlds.size();
    writeInt(worldCount);

    for (int worldIndex = 0; worldIndex < worldCount; ++worldIndex) {
        writeWorld(worlds[worldIndex]);
    }
}

void RemoteProcessClient::ensureMessageType(MessageType actualType, MessageType expectedType) {
    if (actualType != expectedType) {
        exit(10011);
    }
}

template <typename E> E RemoteProcessClient::readEnum() {
    return (E) this->readBytes(1)[0];
}

template <typename E> vector<E> RemoteProcessClient::readEnumArray() {
    int length = readInt();
    if (length < 0) {
        exit(10015);
    }

    vector<E> value;
    value.reserve(length);

    for (int i = 0; i < length; ++i) {
        value.push_back(readEnum<E>());
    }

    return value;
}

template <typename E> vector<vector<E> > RemoteProcessClient::readEnumArray2D() {
    int length = readInt();
    if (length < 0) {
        exit(10016);
    }

    vector<vector<E> > value(length);

    for (int i = 0; i < length; ++i) {
        int length2 = readInt();
        if (length2 < 0) {
            exit(10017);
        }

        vector<E>& value2 = value[i];
        value2.reserve(length2);

        for (int j = 0; j < length2; ++j) {
            value2.push_back(readEnum<E>());
        }
    }

    return value;
}

template <typename E> void RemoteProcessClient::writeEnum(E value) {
    vector<signed char> bytes;
    bytes.push_back(value);
    this->writeBytes(bytes);
}

template <typename E> void RemoteProcessClient::writeEnumArray(const vector<E>& value) {
    int length = value.size();
    writeInt(length);

    for (int i = 0; i < length; ++i) {
        writeEnum<E>(value[i]);
    }
}

template <typename E> void RemoteProcessClient::writeEnumArray2D(const vector<vector<E> >& value) {
    int length = value.size();
    writeInt(length);

    for (int i = 0; i < length; ++i) {
        writeEnumArray<E>(value[i]);
    }
}

string RemoteProcessClient::readString() {
    int length = this->readInt();
    if (length == -1) {
        exit(10014);
    }

    vector<signed char> bytes = this->readBytes(length);
    return string((char*) (&bytes[0]), length);
}

void RemoteProcessClient::writeString(const string& value) {
    vector<signed char> bytes(value.size());
    
    memcpy(&bytes[0], value.c_str(), value.size());

    this->writeInt(static_cast<int>(bytes.size()));
    this->writeBytes(bytes);
}

bool RemoteProcessClient::readBoolean() {
    if (cachedBoolFlag) {
        cachedBoolFlag = false;
        return cachedBoolValue;
    }
    return this->readBytes(1)[0] != 0;
}

void RemoteProcessClient::writeBoolean(bool value) {
    vector<signed char> bytes;
    bytes.push_back((signed char) (value ? 1 : 0));
    this->writeBytes(bytes);
}

int RemoteProcessClient::readInt() {
    vector<signed char> bytes = this->readBytes(INTEGER_SIZE_BYTES);

    if (this->isLittleEndianMachine() != LITTLE_ENDIAN_BYTE_ORDER) {
        reverse(bytes.begin(), bytes.end());
    }

    int value;

    memcpy(&value, &bytes[0], INTEGER_SIZE_BYTES);

    return value;
}

vector<int> RemoteProcessClient::readIntArray() {
    int length = readInt();
    if (length < 0) {
        exit(10018);
    }

    vector<int> value;
    value.reserve(length);

    for (int i = 0; i < length; ++i) {
        value.push_back(readInt());
    }

    return value;
}

vector<vector<int> > RemoteProcessClient::readIntArray2D() {
    int length = readInt();
    if (length < 0) {
        exit(10019);
    }

    vector<vector<int> > value(length);

    for (int i = 0; i < length; ++i) {
        int length2 = readInt();
        if (length2 < 0) {
            exit(10020);
        }

        vector<int>& value2 = value[i];
        value2.reserve(length2);

        for (int j = 0; j < length2; ++j) {
            value2.push_back(readInt());
        }
    }

    return value;
}

void RemoteProcessClient::writeInt(int value) {
    vector<signed char> bytes(INTEGER_SIZE_BYTES);

    memcpy(&bytes[0], &value, INTEGER_SIZE_BYTES);

    if (this->isLittleEndianMachine() != LITTLE_ENDIAN_BYTE_ORDER) {
        reverse(bytes.begin(), bytes.end());
    }

    this->writeBytes(bytes);
}

void RemoteProcessClient::writeIntArray(const vector<int>& value) {
    int length = value.size();
    writeInt(length);

    for (int i = 0; i < length; ++i) {
        writeInt(value[i]);
    }
}

void RemoteProcessClient::writeIntArray2D(const vector<vector<int> >& value) {
    int length = value.size();
    writeInt(length);

    for (int i = 0; i < length; ++i) {
        writeIntArray(value[i]);
    }
}

long long RemoteProcessClient::readLong() {
    vector<signed char> bytes = this->readBytes(LONG_SIZE_BYTES);

    if (this->isLittleEndianMachine() != LITTLE_ENDIAN_BYTE_ORDER) {
        reverse(bytes.begin(), bytes.end());
    }

    long long value;

    memcpy(&value, &bytes[0], LONG_SIZE_BYTES);

    return value;
}

void RemoteProcessClient::writeLong(long long value) {
    vector<signed char> bytes(LONG_SIZE_BYTES);

    memcpy(&bytes[0], &value, LONG_SIZE_BYTES);

    if (this->isLittleEndianMachine() != LITTLE_ENDIAN_BYTE_ORDER) {
        reverse(bytes.begin(), bytes.end());
    }

    this->writeBytes(bytes);
}

double RemoteProcessClient::readDouble() {
    long long value = this->readLong();
    return *((double*) &value);
}

void RemoteProcessClient::writeDouble(double value) {
    this->writeLong(*((long long*) &value));
}

vector<signed char> RemoteProcessClient::readBytes(unsigned int byteCount) {
    vector<signed char> bytes(byteCount);
    unsigned int offset = 0;
    int receivedByteCount;

    while (offset < byteCount && (receivedByteCount = socket.Receive(byteCount - offset)) > 0) {
        memcpy(&bytes[offset], socket.GetData(), receivedByteCount);
        offset += receivedByteCount;
    }

    if (offset != byteCount) {
        exit(10012);
    }

    return bytes;
}

void RemoteProcessClient::writeBytes(const vector<signed char>& bytes) {
    vector<signed char>::size_type byteCount = bytes.size();
    unsigned int offset = 0;
    int sentByteCount;

    while (offset < byteCount && (sentByteCount = socket.Send((uint8*) &bytes[offset], byteCount - offset)) > 0) {
        offset += sentByteCount;
    }

    if (offset != byteCount) {
        exit(10013);
    }
}

bool RemoteProcessClient::isLittleEndianMachine() {
    union {
        uint16 value;
        unsigned char bytes[2];
    } test = {0x0201};

    return test.bytes[0] == 1; 
}

RemoteProcessClient::~RemoteProcessClient() {
    this->close();
}
