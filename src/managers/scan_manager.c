/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2017
** File description:
** scan_manager functions
*/

# include "matchstick.h"

bool lines_error(int lines, map_t *map)
{
	if (lines <= 0) {
		my_putstr(ERR_POS);
		return (true);
	} else if (lines > map->lines) {
		my_putstr(ERR_RANGE);
		return (true);
	}

	return (false);
}

void scan_lines(map_t *map, int *lines)
{
	char *line = NULL;

	my_putstr("Line: ");
	line = get_next_line(0);
	if (line == NULL || !my_str_isnum(line)) {
		my_putstr(ERR_POS);
		free(line);
		scan_lines(map, lines);
		return;
	}

	*lines = my_atoi(line);
	free(line);
	while (lines_error(*lines, map))
		scan_lines(map, lines);
}

bool matches_error(int matches, int lines, map_t *map)
{
	if (matches == 0) {
		my_putstr(ERR_REM);
		return (true);
	} else if (matches < 0) {
		my_putstr(ERR_POS);
		return (true);
	/*} else if (matches > get_available_matches(map, lines - 1)) {
		my_putstr(ERR_ENGT);
		return (true);*/
	} else if (matches > map->max_matches) {
		my_putstr("Error : you cannot remove more than ");
		my_put_nbr(map->max_matches);
		my_putstr(" matches per turn\n");
		return (true);
	}

	return (false);
}

void scan_matches(map_t *map, int *matches, int *lines)
{
	char *line = NULL;

	my_putstr("Matches: ");
	line = get_next_line(0);
	if (line == NULL || !my_str_isnum(line)) {
		my_putstr(ERR_POS);
		free(line);
		scan_lines(map, lines);
		return;
	}

	*matches = my_atoi(line);
	free(line);
	if (matches_error(*matches, *lines, map)) {
		scan_lines(map, lines);
		scan_matches(map, matches, lines);
	}
}
