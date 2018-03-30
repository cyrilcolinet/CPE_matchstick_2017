/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2017
** File description:
** matstick functions
*/

# include "matchstick.h"

int display_help(char *bin)
{
	my_putstr("USAGE:\n\t");
	my_putstr(bin);
	my_putstr(" <lines> <matches>\n\n");
	my_putstr("DESCRIPTION:\n");
	my_putstr("\t-h\tDisplay this help page\n");
	my_putstr("\tlines\tPositive line number\n");
	my_putstr("\tmatches\tPositive max matches possible\n");
	return (0);
}

int matchstick(map_t *map)
{
	srand(time(NULL));
	display_map(map);
	free_all(map);
	return (0);
}

int matchstick_main(int ac, char **av)
{
	int lines = 0;
	int matches = 0;
	map_t *map = NULL;

	if (ac == 3) {
		lines = my_atoi(av[1]);
		matches = my_atoi(av[2]);
		if (lines <= 0 || matches <= 0)
			return (84);

		map = initialize_map(lines, matches);
		if (map == NULL)
			return (84);
		return (matchstick(map));
	} else if (ac == 2 && my_strequ(av[1], "-h")) {
		return (display_help(av[0]));
	}
	my_putstr("Invalid arguments number.\n");
	my_putstr("Usage: ./matchstick <lines> <matches>\n");
	return (84);
}
