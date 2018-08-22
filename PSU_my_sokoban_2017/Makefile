##
## EPITECH PROJECT, 2017
## Project sokoban
## File description:
## Build sokoban binary.
##

MAIN_SRC	=	src/main.c

SRC	= 	src/map_and_win.c\
		src/map.c\
		src/move.c\
		src/strs.c\

UT_SRC	=	tests/main_test.c

OBJ	=	$(MAIN_SRC:.c=.o) $(SRC:.c=.o)

UT_OBJ	=	$(SRC:.c=.o) $(UT_SRC:.c=.o)

CFLAGS	=	-W -Wextra -W -Wall -Wparentheses -Wsign-compare -Wpointer-sign -Wuninitialized -Wunused-but-set-variable -lncurses -I ./include/
LDFLAGS	=	-lcriterion

NAME	=	my_sokoban

CC	=	gcc

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f $(UT_OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f units
	find . -name "*.gcda" -type f -delete
	find . -name "*.gcno" -type f -delete

re: fclean all

test_run:	$(UT_OBJ)
		gcc -o units $(UT_OBJ) $(LDFLAGS) $(CFLAGS)
		./units
