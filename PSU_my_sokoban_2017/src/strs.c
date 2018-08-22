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

int pos(char *map)
{
	int i = 0;

	while (map[i] != 'P') {
		i++;
	}
	return (i);
}

int strcol(char *map)
{
	int i = 0;
	int j = 0;
	while (map[i] != '\0') {
		if (map[i] == '\n')
			j++;
		i++;
	}
	return (j);
}

int strline(char *map)
{
	int j = 0;

	while (map[j] != '\n') {
		j++;
	}
	j+= 1;
	return (j);
}

int my_strx(player_t *player)
{
	int i = 0;
	int j = 0;

	while (player->map[i] != '\0') {
		if (player->map[i] == 'X')
			j++;
		i++;
	}
	return (j);
}
