/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2017
** File description:
** map_manager functions
*/

# include "matchstick.h"

char **create_map(int lines, int max_sticks)
{
	int sticks = 0;
	int key = 0;
	char **array = malloc(sizeof(*array) * (lines + 1));

	if (array == NULL)
		return (NULL);

	for (int i = 0; i < lines; i++) {
		array[i] = my_strconfigure(max_sticks);
		if (array[i] == NULL)
			return (NULL);

		sticks = 1 + i * 2;
		key = (max_sticks - sticks) / 2;
		while (sticks--)
			array[i][key++] = '|';
	}
	array[lines] = NULL;

	for (int i = 0; array[i]; i++)
		printf("%s\n", array[i]);

	return (array);
}

void display_characters(int i, int j, map_t *map)
{
	char tmp = 0;
	char display = '*';

	if (j > 0 || j != map->max_sticks + 1 || i > 0 || i != map->lines + 1) {
		tmp = map->map[i - 1][j - 1];
		display = (tmp ? tmp : ' ');
	}

	my_putchar(display);
}

void display_map(map_t *map)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < map->lines + 2; i++) {
		for (j = 0; j < map->max_sticks + 2; j++) {
			display_characters(i, j, map);
		}
		my_putchar('\n');
	}
}
