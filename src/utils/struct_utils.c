/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2017
** File description:
** struct_utils functions
*/

# include "matchstick.h"

void free_all(map_t *map)
{
	int i = 0;

	for (i = 0; map->map[i] != NULL; i++)
		free(map->map[i]);
	free(map->map);
	free(map);
}

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

	map->lines = lines;
	map->max_matches = matches;
	map->status = 0;

	return (map);
}
