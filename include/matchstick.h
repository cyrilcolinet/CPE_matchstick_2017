/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2017
** File description:
** matstick functions (header file)
*/

# ifndef MATCHSTICK_H
# define MATCHSTICK_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# include "my.h"

typedef struct map_t {
	char 	**map;
	int 	lines;
	int 	max_sticks;
	int		max_matches;
	int 	status;
}	map_t;

int 		display_help(char *bin);
int 		matchstick(map_t *map);
int 		matchstick_main(int ac, char **av);

// utils/struct_utils.c
void 		free_all(map_t *map);
map_t 		*initialize_map(int lines, int matches);

# endif
