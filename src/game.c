/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2017
** File description:
** game functions
*/

# include "matchstick.h"

void game_player_turn(map_t *map)
{
	int lines = -1;
	int matches = -1;

	my_putstr("\nYour turn :\n");
	scan_lines(map, &lines);
	scan_matches(map, &matches, &lines);
}
