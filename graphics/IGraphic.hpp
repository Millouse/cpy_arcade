/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** IGraphic
*/

#pragma once

class IGraphic {
    public:
        virtual ~IGraphic() = default;
        virtual void lib_init() = 0;
        virtual void lib_exit() = 0;
        virtual void asset_load() = 0;
        virtual void window_refresh() = 0;
        virtual void window_clear() = 0;
        virtual void window_close() = 0;
        virtual bool is_open() = 0;
        virtual int get_key() = 0;
        virtual int get_window_size() = 0;
        virtual void print_text(std::string, int, int, bool = false) = 0;

    protected:
    private:
};
