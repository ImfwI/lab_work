#include "multiplayer_game.h"
#include <iostream>


MultiplayerGame::MultiplayerGame() : Game(), minPlayers(2), maxPlayers(4), playerRequirements({}) {}

MultiplayerGame::MultiplayerGame(const std::string& name, const std::string& rules, const std::string& preparation, const std::string& cleanup,const int& minPlayers,const int& maxPlayers, const std::vector<std::string>& playerRequirements)
    : Game(name, rules, preparation, cleanup), minPlayers(minPlayers), maxPlayers(maxPlayers), playerRequirements(playerRequirements) {}

void MultiplayerGame::setMinPlayers(int min) {
    minPlayers = min;
}

int MultiplayerGame::getMinPlayers() const {
    return minPlayers;
}

void MultiplayerGame::setMaxPlayers(int max) {
    maxPlayers = max;
}

int MultiplayerGame::getMaxPlayers() const {
    return maxPlayers;
}

bool MultiplayerGame::canStartGame(const std::vector<std::string>& playerList) const {

    int numPlayers = playerList.size();
    if (numPlayers < minPlayers || numPlayers > maxPlayers) {
        return false;
    }


    for (const auto& requirement : playerRequirements) {
        if (std::find(playerList.begin(), playerList.end(), requirement) == playerList.end()) {
            return false; 
        }
    }

    return true; 
}