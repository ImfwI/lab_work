#include "game.h"
#include "multiplayer_game.h"
#include <vector>
#include <cassert>
#include <iostream>

int main() {
    // Тесты для ЛР1 (класс Game)
    Game defaultGame;
    assert(defaultGame.getName() == "");
    assert(defaultGame.getRules() == "");
    assert(defaultGame.getPreparation() == "");
    assert(defaultGame.getCleanup() == "");

    Game chess("Chess", "Chess rules", "Arrange chess units", "Fold chess units");
    assert(chess.getName() == "Chess");
    assert(chess.getRules() == "Chess rules");
    assert(chess.getPreparation() == "Arrange chess units");
    assert(chess.getCleanup() == "Fold chess units");

    Game copyChess(chess);
    assert(copyChess.getName() == chess.getName());
    assert(copyChess.getRules() == chess.getRules());
    assert(copyChess.getPreparation() == chess.getPreparation());
    assert(copyChess.getCleanup() == chess.getCleanup());

    defaultGame.setName("Monopoly");
    defaultGame.setRules("Monopoly rules");
    defaultGame.setPreparation("Lay out the playing field");
    defaultGame.setCleanup("Fold the playing field");

    assert(defaultGame.getName() == "Monopoly");
    assert(defaultGame.getRules() == "Monopoly rules");
    assert(defaultGame.getPreparation() == "Lay out the playing field");
    assert(defaultGame.getCleanup() == "Fold the playing field");

    chess.displayInfo();

    // Сообщение об успешном прохождении тестов ЛР1
    std::cout << "all tests have been passed (lab №1)" << std::endl;

    MultiplayerGame defaultMultiplayerGame;
    assert(defaultMultiplayerGame.getName() == "");
    assert(defaultMultiplayerGame.getRules() == "");
    assert(defaultMultiplayerGame.getPreparation() == "");
    assert(defaultMultiplayerGame.getCleanup() == "");
    assert(defaultMultiplayerGame.getMinPlayers() == 2);
    assert(defaultMultiplayerGame.getMaxPlayers() == 4);

    MultiplayerGame dnd("D&D", "D&D rules", "Prepare characters", "Clean up", 3, 6, { "Strategy", "Imagination" });
    assert(dnd.getName() == "D&D");
    assert(dnd.getRules() == "D&D rules");
    assert(dnd.getPreparation() == "Prepare characters");
    assert(dnd.getCleanup() == "Clean up");
    assert(dnd.getMinPlayers() == 3);
    assert(dnd.getMaxPlayers() == 6);

    dnd.setMinPlayers(4);
    dnd.setMaxPlayers(8);
    assert(dnd.getMinPlayers() == 4);
    assert(dnd.getMaxPlayers() == 8);

    std::vector<std::string> playerList1 = { "Player1", "Player2", "Player3", "Strategy", "Imagination" };
    assert(dnd.canStartGame(playerList1) == true);  // Должно пройти

    std::vector<std::string> playerList2 = { "Player1", "Player2" }; // Недостаточно игроков
    assert(dnd.canStartGame(playerList2) == false);

    std::vector<std::string> playerList3 = { "Player1", "Player2", "Player3" }; // Нет обязательных требований
    assert(dnd.canStartGame(playerList3) == false);

    // Сообщение об успешном прохождении тестов ЛР2
    std::cout << "all tests have been passed (lab №2)" << std::endl;

    return 0;
}