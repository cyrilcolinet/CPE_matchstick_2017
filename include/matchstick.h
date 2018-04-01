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
# include <time.h>
# include <stdbool.h>

# include "my.h"

# define READ_SIZE 	(128)
# define ERR_POS	("Error : invalid output (positive number expected)\n")
# define ERR_RANGE 	("Error : this line is out of range\n")
# define ERR_ENGT	("Error : not enougth matches on this line\n")
# define ERR_REM	("Error : you have to remove at least one match\n")

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
char 		*get_next_line(int fd);

// managers/map_manager.c
char 		**create_map(int lines, int max_sticks);
void 		display_characters(int i, int j, map_t *map);
void 		display_map(map_t *map);

// managers/scan_manager.c
bool 		check_exit(map_t *map, char *line, bool status);
bool 		lines_error(int lines, map_t *map);
void 		scan_lines(map_t *map, int *lines);
bool 		matches_error(int matches, int lines, map_t *map);
void 		scan_matches(map_t *map, int *matches, int *lines);

# endif
