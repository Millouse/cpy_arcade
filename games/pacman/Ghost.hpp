/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Ghost
*/

#pragma once

#include "../Pos.hpp"
#include "Type.hpp"
#include "../Direction.hpp"

class Ghost {
    public:
        Ghost(int, int, type_t);
        ~Ghost();
        bool isAlive();
        void setAlive(bool);
        pos_t getPos();
        void pathFinding();
        type_t getType();
        void movePlayer();
        void setDirection(direction_t);

    protected:
    private:
        pos_t _pos;
        bool _alive;
        type_t _type;
        direction_t _dir;
};
