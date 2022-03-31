/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** Sfml
*/

#include <iostream>
#include "Sfml.hpp"
#include "../../core/Exception.hpp"

extern "C" IGraphic *gen_graphic()
{
    return new Sfml;
}

Sfml::Sfml()
{}

Sfml::~Sfml()
{}

void Sfml::lib_init()
{
    this->_window.create(sf::VideoMode::getDesktopMode(), "Arcade");
    if (!this->_font.loadFromFile("./assets/font.ttf"))
        throw ExceptionGraphic("Couldn't load font !");
}

void Sfml::lib_exit()
{}

void Sfml::asset_load()
{}

void Sfml::window_refresh()
{
    this->_window.display();
}

void Sfml::window_clear()
{
    this->_window.clear();
}

void Sfml::window_close()
{
    this->_window.close();
}

bool Sfml::is_open()
{
    return this->_window.isOpen();
}

static int convertSfmlAscii(int key)
{
    if (key == sf::Keyboard::Left)
        return 260;
    if (key == sf::Keyboard::Right)
        return 261;
    if (key == sf::Keyboard::Up)
        return 259;
    if (key == sf::Keyboard::Down)
        return 258;
    return -1;
}

int Sfml::get_key()
{
    sf::Event event;

    while (this->_window.pollEvent(event)) {
        if(event.type == sf::Event::Resized)
            this->_window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
        if (event.type == sf::Event::Closed)
            return 'q';
        if (event.type == sf::Event::TextEntered)
            return event.text.unicode;
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Enter)
                return 10;
            if (event.key.code >= sf::Keyboard::Left && event.key.code <= sf::Keyboard::Down)
                return convertSfmlAscii(event.key.code);
        }
    }
    return -1;
}

int Sfml::get_window_size()
{
    return this->_window.getSize().x;
}

void Sfml::print_text(std::string text, int x, int y, bool highlight)
{
    sf::Text txt;
    sf::RectangleShape rect(sf::Vector2f(10, 10));

    txt.setFont(this->_font);
    txt.setString(text);
    txt.setPosition(x, y * 30 + 20);
    txt.setFillColor(sf::Color::White);
    if (highlight) {
        rect.setSize(sf::Vector2f(txt.getLocalBounds().width, txt.getLocalBounds().height + 8));
        rect.setPosition(x, y * 30 + 20);
        rect.setFillColor(sf::Color::White);
        txt.setFillColor(sf::Color::Black);
        this->_window.draw(rect);
    }
    this->_window.draw(txt);
}
