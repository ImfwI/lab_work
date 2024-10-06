#include "game.h"
#include <iostream>

Game::Game() : name(""), rules(""), preparation(""), cleanup("") {}

Game::Game(const std::string& name, const std::string& rules, const std::string& preparation, const std::string& cleanup)
    : name(name), rules(rules), preparation(preparation), cleanup(cleanup) {}

Game::Game(const Game& other)
    : name(other.name), rules(other.rules), preparation(other.preparation), cleanup(other.cleanup) {}

Game::~Game() {}

std::string Game::getName() const { return name; }
std::string Game::getRules() const { return rules; }
std::string Game::getPreparation() const { return preparation; }
std::string Game::getCleanup() const { return cleanup; }

void Game::setName(const std::string& name) {
    if (name.empty()) {
        std::cerr << "Empty game name slot!" << std::endl;
        return;
    }
    this->name = name;
}

void Game::setRules(const std::string& rules) {
    if (rules.empty()) {
        std::cerr << "Empty game rules slot!" << std::endl;
        return;
    }
    this->rules = rules;
}

void Game::setPreparation(const std::string& preparation) {
    if (preparation.empty()) {
        std::cerr << "Empty game preparation slot!" << std::endl;
        return;
    }
    this->preparation = preparation;
}

void Game::setCleanup(const std::string& cleanup) {
    if (cleanup.empty()) {
        std::cerr << "Empty game cleanup slot!" << std::endl;
        return;
    }
    this->cleanup = cleanup;
}

void Game::displayInfo() const {
    std::cout << "Game: " << name << std::endl;
    std::cout << "Rules: " << rules << std::endl;
    std::cout << "Preparation: " << preparation << std::endl;
    std::cout << "Cleanup: " << cleanup << std::endl;
}
