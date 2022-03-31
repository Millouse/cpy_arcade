/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Pacman
*/

#include <iostream>
#include "Pacman.hpp"

extern "C" IGame *gen_game()
{
    return new Pacman;
}

Pacman::Pacman()
{}

Pacman::~Pacman()
{}

int Pacman::game_init()
{
    return 0;
}

int Pacman::game_loop()
{
    return 0;
}
