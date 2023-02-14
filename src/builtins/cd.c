/*
** EPITECH PROJECT, 2022
** cd
** File description:
** minishell1
*/

#include "my_sh.h"

char *get_home(char *env)
{
    char *path = "HOME";

    if (!env)
        return NULL;
    for (int i = 0; env[i] == path[i]; i += 1)
        if (i == 3) {
            return env;
        }
    return NULL;
}

char *home(char **env)
{
    char *home = NULL;

    if (!env)
        return NULL;
    for (int i = 0; env[i] != NULL; i += 1)
        if (get_home(env[i]))
            home = get_home(env[i]);
    if (!home)
        return NULL;
    home += 5;
    return home;
}

int cd_home(char **new_tab, char **env)
{
    char *home_path = NULL;

    if (!new_tab[1]) {
        home_path = home(env);
        if (!home)
            return 0;
        chdir(home_path);
        return 1;
    }
    return 0;
}

int check_errors(char **new_tab, char *next_word)
{
    if (errno == ENAMETOOLONG) {
        my_putstr(new_tab[1]);
        my_putstr(": File name too long.\n");
        return 0;
    }
    if (errno == ENOENT) {
        my_putstr(new_tab[1]);
        my_putstr(": No such file or directory.\n");
        return 0;
    }
    if (errno == EACCES) {
        my_putstr(new_tab[1]);
        my_putstr(": Permission denied.\n");
        return 0;
    }
    return 0;
}

int my_cd(char *new_word, char **new_tab, char **env)
{
    if (my_strcmp(new_word, "cd") == 1) {
        if (!new_tab[1]) {
            cd_home(new_tab, env) == 1;
            return 1;
        }
        if (chdir(new_tab[1]) == -1) {
            check_errors(new_tab, new_word);
            return 1;
        }
    }
    return 0;
}
