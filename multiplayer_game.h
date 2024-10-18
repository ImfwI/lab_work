#ifndef MULTIPLAYER_GAME_H
#define MULTIPLAYER_GAME_H

#include "game.h"
#include <vector>
#include <string>

class MultiplayerGame : public Game {
private:
    int minPlayers;
    int maxPlayers;
    std::vector<std::string> playerRequirements;

public:
    MultiplayerGame();

    MultiplayerGame(const std::string& name, const std::string& rules, const std::string& preparation, const std::string& cleanup,const int& minPlayers,const int& maxPlayers, const std::vector<std::string>& playerRequirements);

    void setMinPlayers(int min);
    void setMaxPlayers(int max);

    int getMinPlayers() const;
    int getMaxPlayers() const;

    bool canStartGame(const std::vector<std::string>& playerList) const;

};

#endif

