/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2017
** File description:
** struct_utils functions
*/

# include "matchstick.h"

map_t *initialize_map(int lines, int matches)
{
	map_t *map = malloc(sizeof(map_t));

	if (map == NULL)
		return (NULL);

	map->max_sticks = 1 + (lines - 1) * 2;
	map->map = create_map(lines, map->max_sticks);
	if (map->>map == NULL) {
		free(map);
		return (NULL);
	}
}
