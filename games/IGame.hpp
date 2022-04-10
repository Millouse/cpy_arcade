/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** IGame
*/

#pragma once

#include <vector>
#include <string>
#include <tuple>
#include "Pos.hpp"

class IGame {
    public:
        virtual ~IGame() = default;
        virtual int gameLoop() = 0;
        virtual void gameKeys(int) = 0;
        virtual void gameRestart() = 0;
        virtual size_t getScore() = 0;
        virtual void saveScore() = 0;
        virtual bool isAlive() = 0;
        virtual void loadMap() = 0;
        virtual void parseMap() = 0;
        virtual std::vector<std::string> getMap() = 0;
        virtual std::vector<std::tuple<char, char, std::string>> getAssets() = 0;
        virtual std::vector<std::pair<char, pos_t>> getElements() = 0;
        virtual void checkCollision() = 0;

    protected:
    private:
};
