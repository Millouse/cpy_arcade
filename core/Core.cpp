/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Core
*/

#include <algorithm>
#include <iostream>
#include <dlfcn.h>
#include "Core.hpp"
#include "Exception.hpp"

typedef IGraphic* (*LibGraphic)();
typedef IGame* (*LibGame)();

Core::Core()
{
    this->handl_graphic = nullptr;
    this->handl_game = nullptr;
    this->lib_graphic = NULL;
    this->lib_game = NULL;
    this->name = "test";
    this->highlight.first = GRAPHICS;
    this->highlight.second = 0;
    this->state = MENU;
}

Core::~Core()
{
    close_graphic();
    close_game();
}

void Core::load_graphic(std::string file)
{
    LibGraphic lib = NULL;

    if (file.find("./", 0) == std::string::npos)
        file.insert(0, "./");
    this->handl_graphic = dlopen(file.c_str(), RTLD_LAZY);
    if (this->handl_graphic == NULL)
        throw ExceptionGame(std::string("dlopen : ") + dlerror() + std::string("\n"));
    lib = (LibGraphic)dlsym(this->handl_graphic, "gen_graphic");
    if (lib == NULL)
        throw ExceptionGame(std::string("dlsym : ") + dlerror() + std::string("\n"));
    this->lib_graphic = lib();
    if (this->graphics.empty())
        this->graphics.push_back(file);
}

void Core::load_game(std::string file)
{
    LibGame lib = NULL;

    if (file.find("./", 0) == std::string::npos)
        file.insert(0, "./");
    this->handl_game = dlopen(file.c_str(), RTLD_LAZY);
    if (this->handl_game == NULL)
        throw ExceptionGame(std::string("dlopen : ") + dlerror() + std::string("\n"));
    lib = (LibGame)dlsym(this->handl_game, "gen_game");
    if (lib == NULL)
        throw ExceptionGame(std::string("dlsym : ") + dlerror() + std::string("\n"));
    this->lib_game = lib();
}

void Core::close_graphic()
{
    if (this->lib_graphic != NULL) {
        this->lib_graphic->lib_exit();
        delete this->lib_graphic;
    }
    if (this->handl_graphic != NULL)
        dlclose(this->handl_graphic);
}

void Core::close_game()
{
    if (this->lib_game != NULL)
        delete this->lib_game;
    if (this->handl_game != NULL)
        dlclose(this->handl_game);
}

void Core::switch_graphic(std::string path)
{
    if (this->graphics.empty())
        throw ExceptionGraphic("you need ad lease 1 graphic library");
    if (this->graphics.size() == 1)
        return;
    close_graphic();
    load_graphic(path);
}

void Core::switch_game(std::string path)
{
    if (this->games.empty())
        throw ExceptionGraphic("you need ad lease 1 game library");
    if (this->games.size() == 1)
        return;
    close_game();
    load_game(path);
}

bool Core::is_graphic_loaded()
{
    if (this->lib_graphic != NULL)
        return true;
    else
        return false;
}

bool Core::is_game_loaded()
{
    if (this->lib_game != NULL)
        return true;
    else
        return false;
}

void Core::load_it(std::filesystem::path file)
{
    void *handl = dlopen(file.c_str(), RTLD_LAZY);

    if (handl == NULL)
        return;
    if (dlsym(handl, "gen_graphic") != NULL)
        this->graphics.push_back(file.string());
    if (dlsym(handl, "gen_game") != NULL)
        this->games.push_back(file.string());
}

void Core::search_libs()
{
    if (std::filesystem::exists("./lib/") == false)
        return;
    for (const auto &file : std::filesystem::directory_iterator("./lib/"))
        if (std::find(this->graphics.begin(), this->graphics.end(), file.path().string()) == this->graphics.end())
            load_it(file.path());
}

void Core::print_options()
{
    int i = 0;
    int x = this->lib_graphic->get_window_size() / 3;

    for (auto & elem : this->graphics) {
        if (this->highlight.first == GRAPHICS)
            this->lib_graphic->print_text(elem, x / 10, i, this->highlight.second == i);
        else
            this->lib_graphic->print_text(elem, x / 10, i);
        i++;
    }

    i = 0;
    for (auto & elem : this->games) {
        if (this->highlight.first == GAMES)
            this->lib_graphic->print_text(elem, x + x / 10, i, this->highlight.second == i);
        else
            this->lib_graphic->print_text(elem, x + x / 10, i);
        i++;
    }

    if (this->highlight.first == NAME)
        this->lib_graphic->print_text(this->name, x * 2 + x / 10, 0, true);
    else
        this->lib_graphic->print_text(this->name, x * 2 + x / 10, 0);
}

void Core::key_man(int key)
{
    if (key == 'q') {
        this->lib_graphic->window_close();
        this->state = EXIT;
    }
    if (key == KEY_DOWN) {
        if (this->highlight.first == GRAPHICS && this->highlight.second == this->graphics.size() - 1)
            this->highlight.second = 0;
        else if (this->highlight.first == GAMES && this->highlight.second == this->games.size() - 1)
            this->highlight.second = 0;
        else if (this->highlight.first == GRAPHICS || this->highlight.first == GAMES)
            this->highlight.second++;
    }
    if (key == KEY_UP) {
        if (this->highlight.first == GRAPHICS && this->highlight.second == 0)
            this->highlight.second = this->graphics.size() - 1;
        else if (this->highlight.first == GAMES && this->highlight.second == 0)
            this->highlight.second = this->games.size() - 1;
        else if (this->highlight.first == GRAPHICS || this->highlight.first == GAMES)
            this->highlight.second--;
    }
    if (key == KEY_RIGHT) {
        if (this->highlight.first == NAME)
            this->highlight.first = GRAPHICS;
        else
            this->highlight.first++;
        if (this->highlight.first == GRAPHICS && this->highlight.second > this->graphics.size() - 1)
            this->highlight.second = this->graphics.size() - 1;
        else if (this->highlight.first == GAMES && this->highlight.second > this->games.size() - 1)
            this->highlight.second = this->games.size() - 1;
        else if (this->highlight.first == NAME)
            this->highlight.second = 0;
    }
    if (key == KEY_LEFT) {
        if (this->highlight.first == GRAPHICS)
            this->highlight.first = NAME;
        else
            this->highlight.first--;
        if (this->highlight.first == GRAPHICS && this->highlight.second > this->graphics.size() - 1)
            this->highlight.second = this->graphics.size() - 1;
        else if (this->highlight.first == GAMES && this->highlight.second > this->games.size() - 1)
            this->highlight.second = this->games.size() - 1;
        else if (this->highlight.first == NAME)
            this->highlight.second = 0;
    }
    if (key == KEY_ENTER) {
        if (this->highlight.first == GRAPHICS)
            this->switch_graphic(this->graphics[this->highlight.second]);
    }
    return;
}

void Core::loop()
{
    auto refresh = std::chrono::high_resolution_clock::now();
    int key = -1;

    while (this->state != EXIT) {
        this->lib_graphic->lib_init();
        while (this->lib_graphic->is_open()) {
            if (std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - refresh).count() > 10000000) {
                this->lib_graphic->window_clear();
                this->print_options();
                this->lib_graphic->window_refresh();
                refresh = std::chrono::high_resolution_clock::now();
            }
            this->key_man(this->lib_graphic->get_key());
        }
        this->lib_graphic->lib_exit();
    }
}

std::vector<std::string> Core::get_graphics()
{
    return this->graphics;
}

std::vector<std::string> Core::get_games()
{
    return this->games;
}
