/*
** EPITECH PROJECT, 2022
** display_env
** File description:
** minishell
*/

#include "my_sh.h"

int display_env(char **env)
{
    if (!env)
        return 84;
    for (int i = 0; env[i] != NULL; env++) {
        my_putstr(env[i]);
        my_putchar('\n');
    }
    return 0;
}
