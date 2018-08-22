/*
** EPITECH PROJECT, 2017
** Project sokoban
** File description:
** Main file.
*/

#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

void my_putchar(char c)
{
	write(1, &c, 1);
}

int my_putstr(char const *str)
{
	int e = 0;

	while (str[e] != '\0') {
		my_putchar(str[e]);
		e = e + 1;
	}
	return (0);
}

void struct_call(player_t *player, char **argv)
{
	player->map = create_map(argv[1]);
	player->save = create_map(argv[1]);
	errors(player->map);
	player->j = strline(player->map);
	player->x = strline(player->map);
	player->nblose = 0;
	player->y = strline(player->map);
	player->xc = strcol(player->map);
	player->i = pos(player->map);
}

int main(int ac, char **argv)
{
	player_t *player = malloc(sizeof(player_t));

	if (ac != 2)
		return (84);
	if (argv[1][0] == '-' && argv[1][1] == 'h' && strlen(argv[1]) == 2) {
		player->map = create_map("documentation");
		my_putstr(player->map);
		return (0);
	}
	struct_call(player, argv);
	initscr();
	keypad(stdscr, true);
	curs_set(0);
	noecho();
	program(player);
	free(player->map);
	free(player);
	return (0);
}
