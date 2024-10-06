#ifndef GAME_H
#define GAME_H

#include <string>

class Game {
private:
    std::string name;
    std::string rules;
    std::string preparation;
    std::string cleanup;

public:
    Game();

    Game(const std::string& name, const std::string& rules, const std::string& preparation, const std::string& cleanup);

    Game(const Game& other);

    ~Game();

    std::string getName() const;
    std::string getRules() const;
    std::string getPreparation() const;
    std::string getCleanup() const;

    void setName(const std::string& name);
    void setRules(const std::string& rules);
    void setPreparation(const std::string& preparation);
    void setCleanup(const std::string& cleanup);

    void displayInfo() const;
};

#endif 
