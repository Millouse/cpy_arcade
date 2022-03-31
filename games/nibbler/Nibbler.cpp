/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Nibbler
*/

#include <iostream>
#include "Nibbler.hpp"

extern "C" IGame *gen_game()
{
    return new Nibbler;
}

Nibbler::Nibbler()
{}

Nibbler::~Nibbler()
{}

int Nibbler::game_init()
{
    return 0;
}

int Nibbler::game_loop()
{
    return 0;
}
