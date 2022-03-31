/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Sdl2
*/

#include <iostream>
#include "Sdl2.hpp"

extern "C" IGraphic *gen_graphic()
{
    return new Sdl2;
}

Sdl2::Sdl2()
{}

Sdl2::~Sdl2()
{}

void Sdl2::lib_init()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_DisplayMode DM;

    SDL_GetCurrentDisplayMode(0, &DM);
    this->_window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, DM.w, DM.h, SDL_WINDOW_SHOWN);
    this->_renderer = SDL_CreateRenderer(this->_window, -1, 0);
    this->_open = true;
}

void Sdl2::lib_exit()
{
    SDL_DestroyRenderer(this->_renderer);
    SDL_DestroyWindow(this->_window);
    SDL_Quit();
}

void Sdl2::asset_load()
{}

void Sdl2::window_refresh()
{
    SDL_RenderPresent(this->_renderer);
}

void Sdl2::window_clear()
{
    SDL_RenderClear(this->_renderer);
}

void Sdl2::window_close()
{
    this->_open = false;
}

bool Sdl2::is_open()
{
    return this->_open;
}

int Sdl2::get_key()
{
    SDL_Event event;

    while (SDL_PollEvent(&event) > 0) {
        if (event.type == SDL_QUIT)
            return 'q';
    }
    return -1;
}

int Sdl2::get_window_size()
{
    return 0;
}

void Sdl2::print_text(std::string text, int x, int y, bool highlight)
{
    SDL_SetRenderDrawColor(this->_renderer, 0, 255, 0, 255);
}
