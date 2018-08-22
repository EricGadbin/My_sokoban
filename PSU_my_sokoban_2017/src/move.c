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

void up(player_t *player)
{
	if (player->map[player->i - player->j] == ' ' || \
	player->map[player->i - player->j] == 'P' ||
	player->map[player->i - player->j] == 'O') {
		player->map[player->i - player->j] = 'P';
		player->save[player->i] == 'O' ?
		(player->map[player->i] = 'O') : (player->map[player->i] = ' ');
		player->i -= player->j;
	}
	else if (player->map[player->i - player->j] == 'X' && \
	(player->map[player->i - player->j - player->j] == ' ' ||
	player->map[player->i - player->j - player->j] == 'O')) {
		player->map[player->i - player->j - player->j] = 'X';
		player->map[player->i - player->j] = 'P';
		player->save[player->i] == 'O' ?
		(player->map[player->i] = 'O') : (player->map[player->i] = ' ');
		player->i -= player->j;
	}
}

void down(player_t *player)
{
	if (player->map[player->i + player->j] == ' ' || \
	(player->map[player->i + player->j] == 'P') ||
	player->map[player->i + player->j] == 'O') {
		player->map[player->i + player->j] = 'P';
		player->save[player->i] == 'O' ?
		(player->map[player->i] = 'O') : (player->map[player->i] = ' ');
		player->i += player->j;
	}
	else if (player->map[player->i + player->j] == 'X' && \
	(player->map[player->i + player->j + player->j] == ' ' ||
	player->map[player->i + player->j + player->j] == 'O')) {
		player->map[player->i + player->j + player->j] = 'X';
		player->map[player->i + player->j] = 'P';
		player->save[player->i] == 'O' ?
		(player->map[player->i] = 'O') : (player->map[player->i] = ' ');
		player->i += player->j;
	}
}

void left(player_t *player)
{
	if (player->map[player->i - 1] == ' ' || \
	player->map[player->i - 1] == 'P' ||
	player->map[player->i - 1] == 'O') {
		player->map[player->i -1] = 'P';
		player->save[player->i] == 'O' ?
		(player->map[player->i] = 'O') : (player->map[player->i] = ' ');
		player->i--;
	}
	else if (player->map[player->i - 1] == 'X' && \
	(player->map[player->i - 2] == ' ' ||
	player->map[player->i - 2] == 'O')) {
		player->map[player->i - 2] = 'X';
		player->map[player->i - 1] = 'P';
		player->save[player->i] == 'O' ?
		(player->map[player->i] = 'O') : (player->map[player->i] = ' ');
		player->i--;
	}
}

void right(player_t *player)
{
	if (player->map[player->i + 1] == ' '|| \
	player->map[player->i + 1] == 'P' ||
	player->map[player->i + 1] == 'O') {
		player->map[player->i + 1] = 'P';
		player->save[player->i] == 'O' ?
		(player->map[player->i] = 'O') : (player->map[player->i] = ' ');
		player->i++;
	}
	else if (player->map[player->i + 1] == 'X' && \
	(player->map[player->i + 2] == ' ' ||
	player->map[player->i + 2] == 'O')) {
		player->map[player->i + 2] = 'X';
		player->map[player->i + 1] = 'P';
		player->save[player->i] == 'O' ?
		(player->map[player->i] = 'O') : (player->map[player->i] = ' ');
		player->i++;
	}
}
