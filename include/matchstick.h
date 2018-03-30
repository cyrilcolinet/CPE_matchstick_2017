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
	char 	**get;
	int 	lines;
	int 	max_sticks;
	int		max_matches;
	int 	status;
}	map_t;

int 		matchstick_main(int ac, char **av);

# endif
