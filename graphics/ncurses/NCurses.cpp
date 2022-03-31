/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** NCurses
*/

#include <iostream>
#include <curses.h>
#include "NCurses.hpp"

extern "C" IGraphic *gen_graphic()
{
    return new NCurses;
}

NCurses::NCurses()
{}

NCurses::~NCurses()
{}

void NCurses::lib_init()
{
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    this->open = true;
}

void NCurses::lib_exit()
{
    curs_set(1);
    endwin();
}

void NCurses::asset_load()
{}

void NCurses::window_refresh()
{
    refresh();
}

void NCurses::window_clear()
{
    clear();
}

void NCurses::window_close()
{
    this->open = false;
}

bool NCurses::is_open()
{
    return this->open;
}

int NCurses::get_key()
{
    return getch();
}

int NCurses::get_window_size()
{
    return COLS;
}

void NCurses::print_text(std::string text, int x, int y, bool highlight)
{
    if (highlight == true) {
        attron(A_REVERSE);
        mvprintw(y, x, text.c_str());
        attroff(A_REVERSE);
    } else
        mvprintw(y, x, text.c_str());
}
