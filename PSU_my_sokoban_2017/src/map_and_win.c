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

char *fs_soko(char const *buffer, int size)
{
	int i = 0;
	char *map = malloc(sizeof(char) * size);

	while (i != size) {
		map[i] = buffer[i];
		i++;
	}
	map[size - 1] = '\0';
	return (map);
}

char *create_map(char *argv)
{
	int i = 0;
	char *buffer = malloc(sizeof(char) * 1920 * 1080);
	char *filepath = argv;
	int fd = open(filepath, O_RDONLY);
	int size = 1920 * 1080;

	i = read(fd, buffer, size);
	if (i == -1 || fd == -1)
		exit(84);
	buffer[i] = '\0';
	close(fd);
	return (buffer);
}

int check_lose(player_t *player)
{
	int i = 0;
	int j = my_strx(player);

	while (player->save[i] != '\0') {
		if (player->map[i] == 'X' && \
		(player->map[i + player->x] == 'X'
		|| player->map[i - player->x] == 'X' ||
		player->save[i + player->x] == '#' ||
		player->save[i - player->x] == '#') &&
		(player->map[i + 1] == 'X' || player->map[i - 1] == 'X' ||
		player->save[i + 1] == '#' || player->save[i - 1] == '#'))
			player->nblose++;
		i++;
	}
	if (player->nblose == j)
		return (1);
	player->nblose = 0;
	return (0);
}

int check_win(player_t *player)
{
	int i = 0;

	while (player->save[i] != '\0') {
		if (player->save[i] == 'O' && player->map[i] != 'X')
			return (0);
		i++;
	}
	return (1);
}

void newmap(player_t *player)
{
	int i = 0;
	while (player->save[i] != '\0') {
		player->map[i] = player->save[i];
		i++;
	}
	player->i = pos(player->map);
	player->j = strline(player->map);
	player->y = strline(player->map);
	player->xc = strcol(player->map);
}
