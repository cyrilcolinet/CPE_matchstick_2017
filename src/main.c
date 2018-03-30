/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2017
** File description:
** main file
*/

# include "matchstick.h"

int main(int ac, char **av, char **env)
{
	int res = 64;

	if (*env == NULL)
		return (84);

	res = matchstick_main(ac, av);
	return (res);
}
