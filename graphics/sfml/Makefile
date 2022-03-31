##
## EPITECH PROJECT, 2022
## Untitled (Workspace)
## File description:
## Makefile
##


### SOURCES ###
#----c_sources----#
SRC		:= Sfml.cpp
#------other------#
OBJ		:= $(SRC:.cpp=.o)
INC		:= -I ./
### SOURCES ###


### COMPILE_USEFULL ###
#----general_usefull----#
CC			= g++
#----project_usefull----#
NAME		= arcade_sfml.so
#MAKEFLAGS 	+= --no-print-directory
#MFLAGS		+=	-sC
CPPFLAGS	:= $(INC) -fPIC -g
CFLAGS		:= -std=c++20 -Wall -Wextra
#CFLAGS		+= -Werror
#CFLAGS		+= -g3
LDFLAGS		:= -shared -lsfml-graphics -lsfml-window -lsfml-system
### COMPILE_USEFULL ###


all:		$(OBJ)
			$(CC) -o ../../lib/$(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
			$(RM) -rf $(OBJ) *.gc* *.o vgcore.*

fclean:		clean
			$(RM) -rf ../../lib/$(NAME) a.out

re:			fclean all

.PHONY:		all clean fclean re