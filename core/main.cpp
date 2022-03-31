/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** main
*/

#include <iostream>
#include <ostream>
#include "Core.hpp"
#include "Exception.hpp"

int main(int ac, char * const *av)
{
  Core *core = new Core();

  if (ac != 2) {
    std::cerr << "You need to give a single graphic lib to load" << std::endl;
    return 84;
  }
  try {
    core->load_graphic(std::string(av[1]));
    if (core->is_graphic_loaded() == false)
      return 84;
    core->search_libs();
    core->loop();
  } catch (const ExceptionGraphic& e) {
    std::cerr << "An error append in the graphic library" << std::endl;
    std::cerr << e.what() << std::endl;
    return 84;
  } catch (const ExceptionGame& e) {
    std::cerr << "An error append in the game library" << std::endl;
		std::cerr << e.what() << std::endl;
		return 84;
  }
  return 0;
}