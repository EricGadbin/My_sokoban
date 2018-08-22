/*
** EPITECH PROJECT, 2017
** epitech
** File description:
** my
*/

#include <sys/stat.h>
#include <dirent.h>

#ifndef MY_H_
#define MY_H_

typedef struct player_s {
	int i;
	int j;
	int x;
	int y;
	int xc;
	int nblose;
	int is;
	char *map;
	char *save;

} player_t;

char *create_map(char *);
char *fs_soko(char const *, int);
int pos(char *);
int strline(char *);
void up(player_t *);
void down(player_t *);
void left(player_t *);
void right(player_t *);
int check_win(player_t *);
void newmap(player_t *);
int program(player_t *);
int errors(char *);
int strcol(char *);
int my_strx(player_t *);
int check_lose(player_t *);

#endif /* MY_H_ */
