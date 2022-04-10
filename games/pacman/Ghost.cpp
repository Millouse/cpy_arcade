/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Ghost
*/

#include "Ghost.hpp"

Ghost::Ghost(int x, int y, type_t type)
{
    _pos.x = x;
    _pos.y = y;
    _alive = true;
    _type = type;
}

Ghost::~Ghost()
{}

bool Ghost::isAlive()
{
    return _alive;
}

void Ghost::setAlive(bool alive)
{
    _alive = alive;
}

pos_t Ghost::getPos()
{
    return _pos;
}

void Ghost::pathFinding()
{
    // si face un mur, en fonction du sens ou on est on check les autres sens et on fais un random pour ou touner
    // ensuite on call setDirection avec cette direction
}

type_t Ghost::getType()
{
    return _type;
}

void Ghost::movePlayer()
{
    // ici modifier la pos de tout player en fonction de la direction
}

void Ghost::setDirection(direction_t dir)
{
    _dir = dir;
}
