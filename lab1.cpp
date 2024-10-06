#include "game.h"
#include <cassert>
#include <iostream>

int main() {
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

    std::cout << "all tests have been passed" << std::endl;

    return 0;
}
