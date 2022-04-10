/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** IGraphic
*/

#pragma once

#include <vector>
#include <tuple>
#include <string>
#include "../games/Pos.hpp"

class IGraphic {
    public:
        virtual ~IGraphic() = default;
        virtual void assetsLoad(std::vector<std::tuple<char, char, std::string>>) = 0;
        virtual void windowRefresh() = 0;
        virtual void windowClear() = 0;
        virtual void windowClose() = 0;
        virtual bool isRunning() = 0;
        virtual int getKey() = 0;
        virtual int getSize() = 0;
        virtual void printText(std::string, pos_t) = 0;
        virtual void printMap(std::vector<std::string>, pos_t) = 0;
        virtual void printElements(std::vector<std::pair<char, pos_t>>, pos_t) = 0;
        virtual int findTuple(char) = 0;

    protected:
    private:
};
