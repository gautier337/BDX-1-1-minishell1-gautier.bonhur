/*
** EPITECH PROJECT, 2022
** get_line
** File description:
** minishell1
*/

#include "my_sh.h"

int get_line(int argc, char **argv, char **env)
{
    char *sentence = NULL;
    char **all_paths = calls_path_env(env);
    size_t len = 0;
    ssize_t what_i_read;
    int i = 0;

    if (!argv || !env || !all_paths)
        return 84;
    for (;(what_i_read = getline(&sentence, &len, stdin)) != -1;) {
        if (check_cmd(sentence, env, all_paths) == 84)
            return 84;
        my_putstr(getcwd(NULL, 0));
        my_putstr("> ");
    }
    return 0;
}
