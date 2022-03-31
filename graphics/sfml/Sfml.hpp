/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Sfml
*/

#pragma once

#include "../IGraphic.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Sfml : public IGraphic {
    public:
        Sfml();
        ~Sfml();
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
        sf::Font _font;
        sf::RenderWindow _window;
};
