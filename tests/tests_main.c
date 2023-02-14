/*
** EPITECH PROJECT, 2022
** criterion test
** File description:
** minishell
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_sh.h"

Test(my_strcmp, test_compare)
{
    int return_number = my_strcmp("salut", "salut");

    cr_assert_eq(1, return_number);
}

Test(put_str_in_tab_of_tab, tab_tab1)
{
    char **new_tab = put_str_in_tab_of_tab("salut ça va ou pas ?", ' ');

    cr_assert_str_eq("salut", new_tab[0]);
}

Test(put_str_in_tab_of_tab, tab_tab2)
{
    char **new_tab = put_str_in_tab_of_tab("salut ça va ou pas ?", ' ');

    cr_assert_str_eq("ça", new_tab[1]);
}

Test(put_str_in_tab_of_tab, tab_tab3)
{
    char **new_tab = put_str_in_tab_of_tab("salut ça va ou pas ?", ' ');

    cr_assert_str_eq("va", new_tab[2]);
}