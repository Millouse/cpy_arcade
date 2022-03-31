/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Pacman
*/

#pragma once

#include "../IGame.hpp"

class Pacman : public IGame {
    public:
        Pacman();
        ~Pacman();
        virtual int game_init();
        virtual int game_loop();

    protected:
    private:
};
