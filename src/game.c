/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2017
** File description:
** game functions
*/

# include "matchstick.h"

int get_random_match_line(map_t *map, int *line, bool set_line)
{
	int max = map->lines;
	int min = 1;
	int r = 0;

	srandom(time(NULL));
	if (set_line) {
		r = (random() % (max - min)) + min;
		if (r <= 0 || r > max)
			return (get_random_match_line(map, NULL, true));
		return (r);
	}

	max = get_available_matches(map, *line - 1);
	if (max > 0) {
		return (((max == min) ? 1 : (random() % (max - min)) + min));
	} else {
		*line = ((*line + 1 > map->lines) ? 1 : *line + 1);
		return (get_random_match_line(map, line, false));
	}
}

void game_ai_turn(map_t *map)
{
	int matches = 0;
	int line = get_random_match_line(map, NULL, true);

	my_putstr("\nAI's turn...\n");
	matches = get_random_match_line(map, &line, false);

	while (matches > map->max_matches)
		matches = get_random_match_line(map, &line, false);

	remove_matches(map, line, matches, false);
	display_map(map);
	if (map_is_empty(map)) {
		my_putstr("I lost... snif... but I'll get you next time!!\n");
		map->status = 1;
		return;
	}

	game_player_turn(map);
}

void game_player_turn(map_t *map)
{
	int lines = -1;
	int matches = -1;

	my_putstr("\nYour turn :\n");
	scan_lines(map, &lines);
	scan_matches(map, &matches, &lines);
	if (map->status == -1) {
		map->status = 0;
		return;
	}
	remove_matches(map, lines, matches, true);
	display_map(map);
	if (map_is_empty(map)) {
		my_putstr("You lost, too bad...\n");
		map->status = 2;
		return;
	}

	game_ai_turn(map);
}
