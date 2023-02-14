/*
** EPITECH PROJECT, 2022
** main
** File description:
** minishell1
*/

#include "my_sh.h"

int main(int argc, char **argv, char **env)
{
    if (!argv || !env)
        return 84;
    if (argc > 1) {
        my_putstr(argv[1]);
        my_putstr(": No such file or directory.\n");
        return 84;
    }
    return my_sh(argc, argv, env);
}
