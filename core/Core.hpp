/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Core
*/

#pragma once

#include <vector>
#include <string>
#include <filesystem>
#include "../graphics/IGraphic.hpp"
#include "../games/IGame.hpp"

typedef enum keys_e {
    KEY_UP = 259,
    KEY_DOWN = 258,
    KEY_LEFT = 260,
    KEY_RIGHT = 261,
    KEY_ENTER = 10
} keys_t;

typedef enum section_e {
    GRAPHICS,
    GAMES,
    NAME
} section_t;

typedef enum state_e {
    MENU,
    GAME,
    EXIT
} state_t;

class Core {
    public:
        Core();
        ~Core();
        void search_libs();
        void load_graphic(std::string);
        void load_game(std::string);
        void close_graphic();
        void close_game();
        void switch_graphic(std::string);
        void switch_game(std::string);
        void load_it(std::filesystem::path);
        bool is_graphic_loaded();
        bool is_game_loaded();
        std::vector<std::string> get_graphics();
        std::vector<std::string> get_games();
        void loop();
        void print_options();
        void key_man(int);

    protected:
    private:
        std::vector<std::string> graphics;
        std::vector<std::string> games;
        void *handl_graphic;
        void *handl_game;
        IGraphic *lib_graphic;
        IGame *lib_game;
        std::string name;
        std::pair<int, int> highlight;
        state_t state;
};
