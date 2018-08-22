/*
** EPITECH PROJECT, 2017
** Project sokoban Testing
** File description:
** Unit Testing Project sokoban
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <ctype.h>
#include "my.h"

void main_redirect_stdout(void)
{
	cr_redirect_stdout();
}

Test(sokoban, check_player_position)
{
	player_t *maps;
	char *map = ("##########\n"\
				   "#        #\n"\
				   "#        #\n"\
				   "# PXO  ###\n"\
			           "#        #\n"\
				   "# OX     #\n"\
				   "##########\n");
	pos = get_player_position(map);
	cr_assert_neq(pos, NULL);
	cr_assert_eq(pos->x, 2);
	cr_assert_eq(pos->y, 3);
}
