/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2017
** File description:
** matchstick_random_tests CRITERION
*/

# include "matchstick.h"
# include <criterion/criterion.h>
# include <criterion/redirect.h>

static void redirect_stdall(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(matchstick, random, .init = redirect_stdall)
{
	
}
