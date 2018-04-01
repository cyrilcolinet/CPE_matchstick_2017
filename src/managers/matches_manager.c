/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2017
** File description:
** matches_manager functions
*/

# include "matchstick.h"

int get_available_matches(map_t *map, int line)
{
	int i = 0;
	int matches = 0;

	for (i = 0; i < map->max_sticks; i++)
		matches += map->map[line][i] == '|' ? 1 : 0;
	return (matches);
}
