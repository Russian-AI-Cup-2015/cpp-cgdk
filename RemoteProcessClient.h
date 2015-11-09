#pragma once

#ifndef _REMOTE_PROCESS_CLIENT_H_
#define _REMOTE_PROCESS_CLIENT_H_

#include <string>
#include <vector>

#include "csimplesocket/ActiveSocket.h"
#include "model/Game.h"
#include "model/Move.h"
#include "model/PlayerContext.h"
#include "model/World.h"

enum MessageType {
    UNKNOWN_MESSAGE,
    GAME_OVER,
    AUTHENTICATION_TOKEN,
    TEAM_SIZE,
    PROTOCOL_VERSION,
    GAME_CONTEXT,
    PLAYER_CONTEXT,
    MOVES_MESSAGE
};

class RemoteProcessClient {
private:
    CActiveSocket socket;
    bool cachedBoolFlag;
    bool cachedBoolValue;

    std::string mapName;
    std::vector<std::vector<model::TileType> > tilesXY;
    std::vector<std::vector<int> > waypoints;
    model::Direction startingDirection;

    model::Bonus readBonus();
    void writeBonus(const model::Bonus& bonus);
    std::vector<model::Bonus> readBonuses();
    void writeBonuses(const std::vector<model::Bonus>& bonuses);
    model::Car readCar();
    void writeCar(const model::Car& car);
    std::vector<model::Car> readCars();
    void writeCars(const std::vector<model::Car>& cars);
    model::Game readGame();
    void writeGame(const model::Game& game);
    std::vector<model::Game> readGames();
    void writeGames(const std::vector<model::Game>& games);
    model::Move readMove();
    void writeMove(const model::Move& move);
    std::vector<model::Move> readMoves();
    void writeMoves(const std::vector<model::Move>& moves);
    model::OilSlick readOilSlick();
    void writeOilSlick(const model::OilSlick& oilSlick);
    std::vector<model::OilSlick> readOilSlicks();
    void writeOilSlicks(const std::vector<model::OilSlick>& oilSlicks);
    model::Player readPlayer();
    void writePlayer(const model::Player& player);
    std::vector<model::Player> readPlayers();
    void writePlayers(const std::vector<model::Player>& players);
    model::PlayerContext readPlayerContext();
    void writePlayerContext(const model::PlayerContext& playerContext);
    std::vector<model::PlayerContext> readPlayerContexts();
    void writePlayerContexts(const std::vector<model::PlayerContext>& playerContexts);
    model::Projectile readProjectile();
    void writeProjectile(const model::Projectile& projectile);
    std::vector<model::Projectile> readProjectiles();
    void writeProjectiles(const std::vector<model::Projectile>& projectiles);
    model::World readWorld();
    void writeWorld(const model::World& world);
    std::vector<model::World> readWorlds();
    void writeWorlds(const std::vector<model::World>& worlds);

    static void ensureMessageType(MessageType actualType, MessageType expectedType);

    template <typename E> E readEnum();
    template <typename E> std::vector<E> readEnumArray();
    template <typename E> std::vector<std::vector<E> > readEnumArray2D();
    template <typename E> void writeEnum(E value);
    template <typename E> void writeEnumArray(const std::vector<E>& value);
    template <typename E> void writeEnumArray2D(const std::vector<std::vector<E> >& value);

    std::string readString();
    void writeString(const std::string& value);

    bool readBoolean();
    void writeBoolean(bool value);

    int readInt();
    std::vector<int> readIntArray();
    std::vector<std::vector<int> > readIntArray2D();
    void writeInt(int value);
    void writeIntArray(const std::vector<int>& value);
    void writeIntArray2D(const std::vector<std::vector<int> >& value);

    long long readLong();
    void writeLong(long long value);

    double readDouble();
    void writeDouble(double value);

    std::vector<signed char> readBytes(unsigned int byteCount);
    void writeBytes(const std::vector<signed char>& bytes);

    static bool isLittleEndianMachine();
public:
    RemoteProcessClient(std::string host, int port);

    void writeTokenMessage(const std::string& token);
    int readTeamSizeMessage();
    void writeProtocolVersionMessage();
    model::Game readGameContextMessage();
    model::PlayerContext* readPlayerContextMessage();
    void writeMovesMessage(const std::vector<model::Move>& move);

    void close();

    ~RemoteProcessClient();
};

#endif
