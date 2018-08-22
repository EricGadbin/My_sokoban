/*
** EPITECH PROJECT, 2017
** epitech
** File description:
** sokoban
*/

#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

void printmap(player_t *player)
{
	printw(player->map);
}

void switcher(player_t *player)
{
	switch (wgetch(stdscr)) {
	case KEY_UP:
		up(player);
		break;
	case KEY_DOWN:
		down(player);
		break;
	case KEY_LEFT:
		left(player);
		break;
	case KEY_RIGHT:
		right(player);
		break;
	case 32:
		newmap(player);
		break;
	case 27:
		endwin();
		free(player);
		exit (0);
	}
}

int errors(char *str)
{
	int i = 0;
	int a = 0;
	int b = 0;

	while (str[i] != '\0') {
		if (str[i] != 'P' && str[i] != 'X' && str[i] != ' ' && \
		str[i] != 'O' && str[i] != '\n' && str[i] != '#')
			exit(84);
		if (str[i] == 'X')
			a += 1;
		if (str[i] == 'O')
			b += 1;
		i++;
	}
	if (a != b)
		exit (84);
	return (0);
}

int toosmall(player_t*player)
{
	while ((COLS < player->y) || (LINES < player->xc)) {
		mvprintw(LINES / 2, (COLS - 49) / 2, \
		"Window to small for the level, please resize it.");
		refresh();
		clear();
	}
	return (1);
}

int program(player_t *player)
{
	while (toosmall(player) == 1) {
		printmap(player);
		refresh();
		switcher(player);
		if (check_win(player) == 1) {
			refresh();
			endwin();
			return (0);
		}
		if (check_lose(player) == 1) {
			refresh();
			endwin();
			return (1);
		}
		clear();
	}
	return (0);
}
