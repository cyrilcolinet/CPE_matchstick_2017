/*
** EPITECH PROJECT, 2018
** CPE_matchstick_2017
** File description:
** matchstick_basics_tests CRITERION
*/

# include "matchstick.h"
# include <criterion/criterion.h>
# include <criterion/redirect.h>

static void redirect_stdall(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(matchstick, wrong_args_number, .init = redirect_stdall)
{
	int res = 0;
	char *args[] = { "./matchstick" };

	res = matchstick_main(1, args);
	cr_assert_eq(res, 84);
}
