/*
** EPITECH PROJECT, 2022
** setenv
** File description:
** minishell1
*/

#include "my_sh.h"

char **my_setenv(char **env, char *sentence)
{
    char **new_tab = NULL;

    if (!(new_tab = put_str_in_tab_of_tab(sentence, ' '))
        || !env)
        return NULL;
    return env;
}
