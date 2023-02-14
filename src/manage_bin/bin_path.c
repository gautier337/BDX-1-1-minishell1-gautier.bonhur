/*
** EPITECH PROJECT, 2022
** find_the_path
** File description:
** bin_path
*/

#include "my_sh.h"

char **get_all_path(int i, char *env)
{
    char **new = NULL;

    if (!env)
        return NULL;
    env += 5;
    if (!(new = put_str_in_tab_of_tab(env, ':')))
        return NULL;
    return new;
}

char **get_path(char *env)
{
    char *path = "PATH";
    char **all_paths = NULL;

    if (!env)
        return NULL;
    for (int i = 0; env[i] == path[i]; i += 1)
        if (i == 3)
            all_paths = get_all_path(i, env);
    if (!all_paths)
        return NULL;
    return all_paths;
}

char **calls_path_env(char **env)
{
    char **all_paths = NULL;

    if (!env)
        return NULL;
    for (int i = 0; env[i] != NULL; i += 1)
        if (get_path(env[i]))
            all_paths = get_path(env[i]);
    if (!all_paths)
        return NULL;
    return all_paths;
}
