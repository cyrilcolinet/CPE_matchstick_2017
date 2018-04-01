/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2017
** File description:
** game functions
*/

# include "matchstick.h"

void game_ai_turn(map_t *map)
{
	int av = 0;
	int matches = 0;

	my_putstr("\nAI's turn...\n");
	for (int i = 0; i < map->lines; i++) {
		av = get_available_matches(map, i);
		if (av > 0) {
			srand(time(NULL));
			matches = ((av > 1) ? (rand() % av) + 1 : 1);
			if (matches <= map->max_matches) {
				remove_matches(map, i + 1, matches, false);
				break;
			}
		}
	}
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
