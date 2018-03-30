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
	char **array = malloc(sizeof(*array) * lines);

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

	return (array);
}
