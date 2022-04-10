/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Pacman
*/

#include <fstream>
#include <iostream>
#include "Pacman.hpp"
#include "../../core/Exception.hpp"

extern "C" IGame *genGame()
{
    return new Pacman;
}

extern "C" std::string getId()
{
    return "Pacman";
}

Pacman::Pacman()
{
    _player = nullptr;
    gameRestart();
}

Pacman::~Pacman()
{
    delete _player;
}

int Pacman::gameLoop()
{
    pos_t playerPos = _player->getPos();

    _player->movePlayer(_map);
    checkCollision();
    if (_map[playerPos.y][playerPos.x] == '.' || _map[playerPos.y][playerPos.x] == 'o') {
        ++_score;
        _map[playerPos.y][playerPos.x] = ' ';
    }
    return 0;
}

void Pacman::gameKeys(int key)
{
    if (key == 'q')
        _player->setDirection(LEFT);
    if (key == 'd')
        _player->setDirection(RIGHT);
    if (key == 'z')
        _player->setDirection(UP);
    if (key == 's')
        _player->setDirection(DOWN);
}

void Pacman::gameRestart()
{
    if (_player != nullptr) {
        delete _player;
        _player = nullptr;
    }
    _ghost.clear();
    loadMap();
    parseMap();
    _score = 0;
}

size_t Pacman::getScore()
{
    return _score;
}

void Pacman::saveScore()
{}

bool Pacman::isAlive()
{
    return (_player != NULL) ? _player->isAlive() : false;
}

void Pacman::loadMap()
{
    std::ifstream file("./assets/Pacman/map");
    std::string line;

    _map.clear();
    if (!file)
        throw ExceptionGame("pacman : ./assets/Pacman/map file not found");
    while (std::getline(file, line))
        _map.push_back(line);
}

static type_t checkType(char c)
{
    switch (c) {
        case 'N':
            return ONE;
        case 'M':
            return TWO;
        case 'W':
            return THREE;
        case 'V':
            return FOUR;
        default:
            return UNKNOWN;
    }
}

void Pacman::parseMap()
{
    for (size_t y = 0; y < _map.size(); ++y)
        for (size_t x = 0; x < _map[y].size(); ++x) {
            if (_map[y][x] == 'P') {
                if (_player != nullptr)
                    throw ExceptionGame("pacman : to many players found in the map");
                _player = new Player(x, y);
                _map[y].replace(x, 1, " ");
            }
            if (_map[y][x] == 'N' || _map[y][x] == 'M' || _map[y][x] == 'W' || _map[y][x] == 'V') {
                _ghost.push_back(new Ghost(x, y, checkType(_map[y][x])));
                _map[y].replace(x, 1, " ");
            }
        }
    if (_player == nullptr)
        throw ExceptionGame("pacman : no player found in the map");
}

std::vector<std::string> Pacman::getMap()
{
    return _map;
}

std::vector<std::tuple<char, char, std::string>> Pacman::getAssets()
{
    std::vector<std::tuple<char, char, std::string>> assets;

    assets.push_back({'P', 'P', "./assets/Pacman/player.png"});
    assets.push_back({'N', 'G', "./assets/Pacman/ghost1.png"});
    assets.push_back({'M', 'G', "./assets/Pacman/ghost2.png"});
    assets.push_back({'W', 'G', "./assets/Pacman/ghost3.png"});
    assets.push_back({'V', 'G', "./assets/Pacman/ghost4.png"});
    assets.push_back({'.', '.', "./assets/Pacman/point.png"});
    assets.push_back({'o', 'o', "./assets/Pacman/power.png"});
    assets.push_back({'#', '#', "./assets/wall.png"});
    assets.push_back({' ', ' ', "./assets/empty.png"});
    assets.push_back({'X', ' ', "./assets/empty.png"});
    return assets;
}

std::vector<std::pair<char, pos_t>> Pacman::getElements()
{
    std::vector<std::pair<char, pos_t>> elements;

    elements.push_back(std::make_pair('P', _player->getPos()));
    for (const auto& elem : _ghost)
        elements.push_back(std::make_pair(elem->getType(), elem->getPos()));
    return elements;
}

void Pacman::checkCollision()
{
    pos_t pos = _player->getPos();
    pos_t tpRight = { .x = 0, .y = 12};
    pos_t tpLeft = { .x = 22, .y = 12};

    if (_map[pos.y][pos.x] == '#')
        _player->setPos(_player->getLastPos());
    if (pos.x == 23 && pos.y == 12) {
        _player->setPos(tpRight);
        _player->setDirection(RIGHT);
    }
    if (pos.x == 0 && pos.y == 12) {
        _player->setPos(tpLeft);
        _player->setDirection(LEFT);
    }
    if (_map[pos.y][pos.x] == 'o') {
        _player->setPower(true);
        _player->setPowerDuration(_player->getPowerDuration() + 35);
    }
}