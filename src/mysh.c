/*
** EPITECH PROJECT, 2022
** my_sh
** File description:
** mysh
*/

#include "my_sh.h"

int my_sh(int argc, char **argv, char **env)
{
    my_putstr(getcwd(NULL, 0));
    my_putstr("> ");
    if (get_line(argc, argv, env) == 84)
        return 84;
    return 0;
}
