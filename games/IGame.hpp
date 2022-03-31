/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** IGame
*/

#pragma once

class IGame {
    public:
        virtual ~IGame() = default;
        virtual int game_init() = 0;
        virtual int game_loop() = 0;

    protected:
    private:
};
