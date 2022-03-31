/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Sdl2
*/

#pragma once

#include "../IGraphic.hpp"
#include <SDL2/SDL.h>

class Sdl2 : public IGraphic {
    public:
        Sdl2();
        ~Sdl2();
        virtual void lib_init();
        virtual void lib_exit();
        virtual void asset_load();
        virtual void window_refresh();
        virtual void window_clear();
        virtual void window_close();
        virtual bool is_open();
        virtual int get_key();
        virtual int get_window_size();
        virtual void print_text(std::string, int, int, bool = false);

    protected:
    private:
        SDL_Window* _window;
        SDL_Renderer* _renderer;
        bool _open;
};
