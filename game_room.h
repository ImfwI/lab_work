// game_room.h
#ifndef GAME_ROOM_H
#define GAME_ROOM_H

#include "multiplayer_game.h"
#include <vector>
#include <string>

class GameRoom {
private:
    std::vector<MultiplayerGame> games;
    std::vector<std::string> teachers;

public:
    GameRoom();

    void addGame(const MultiplayerGame& game);
    void addTeacher(const std::string& teacher);
    MultiplayerGame pickGameForTeachers(const std::vector<std::string>& teacherSubset) const;
};

#endif
#pragma once
