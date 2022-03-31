/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** NCurses
*/

#pragma once

#include "../IGraphic.hpp"

class NCurses : public IGraphic {
    public:
        NCurses();
        ~NCurses();
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
        bool open;
};
