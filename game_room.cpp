// game_room.cpp
#include "game_room.h"
#include <algorithm>
#include <stdexcept>
#include <iostream>

GameRoom::GameRoom() : games(), teachers() {}

void GameRoom::addGame(const MultiplayerGame& game) {
    games.push_back(game);
}

void GameRoom::addTeacher(const std::string& teacher) {
    teachers.push_back(teacher);
}

MultiplayerGame GameRoom::pickGameForTeachers(const std::vector<std::string>& teacherSubset) const {
    for (const auto& game : games) {
        int numTeachers = teacherSubset.size();

        // Проверка по количеству игроков
        if (numTeachers < game.getMinPlayers() || numTeachers > game.getMaxPlayers()) {
            continue;
        }

        // Проверка выполнения требований игры
        bool allRequirementsMet = true;
        for (const auto& requirement : game.getPlayerRequirements()) {
            if (std::find(teacherSubset.begin(), teacherSubset.end(), requirement) == teacherSubset.end()) {
                allRequirementsMet = false;
                break;
            }
        }

        if (allRequirementsMet) {
            return game;
        }
    }

    throw std::runtime_error("No suitable game found for the given teachers.");
}
