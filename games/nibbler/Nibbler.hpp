/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Nibbler
*/

#pragma once

#include "../IGame.hpp"

class Nibbler : public IGame {
    public:
        Nibbler();
        ~Nibbler();
        virtual int game_init();
        virtual int game_loop();

    protected:
    private:
};
