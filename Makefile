##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## rule them all
##

CC	=	gcc

FILE	=	sources/sokoban.c  \
		sources/game.c	\
		sources/usage.c	\
		sources/map.c	\
		sources/player.c	\
		sources/controls.c	\
		sources/boxes_and_targets.c	\
		sources/error_handling.c	\
		sources/reset.c	\
		sources/lose.c	\

NAME	=	my_sokoban

OBJ	=	$(FILE:.c=.o)

VALGRIND	=	-g

LIB	=	-L ./sources/lib -lmy -lncurses

CFLAGS	=	-Wextra -Wall

CPPFLAGS	=	-I ./includes

all:	sokoban

sokoban:	$(OBJ)
	make -C ./sources/lib/my
	$(CC) -o $(NAME) $(OBJ) $(LIB)
	@echo -e "\n\e[92mSuccessfully compiled\e[0m"

debug:	$(OBJ)
	make -C ./sources/lib/my
	$(CC) $(VALGRIND) -o $(NAME) $(OBJ) $(LIB)
	@echo -e "\n\e[92mEnjoy :)\e[0m"

clean:
	make clean -C ./sources/lib/my
	rm -f *.o
	rm -f sources/*.o

fclean:	clean
	make fclean -C ./sources/lib/my
	rm -f $(NAME)
	@echo -e "\n\e[92mSuccessfully cleaned\e[0m"

re:	fclean all

.PHONY:	clean fclean re all sokoban
