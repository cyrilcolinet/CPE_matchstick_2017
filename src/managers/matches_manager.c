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

void remove_matches(map_t *map, int line, int matches, bool player)
{
	int max = map->max_sticks;
	int removed = matches;
	char *str = NULL;

	for (; max >= 0 && matches; max--) {
		str = &map->map[line - 1][max];
		if (*str == '|' && matches--)
			*str = 0;
	}

	my_putstr(player ? "Player": "AI");
	my_putstr(" removed ");
	my_put_nbr(removed);
	my_putstr(" match(es) from line ");
	my_put_nbr(line);
	my_putstr("\n");
}
