/*
** EPITECH PROJECT, 2022
** str_to_tab
** File description:
** maintab
*/

#include "lib.h"

char **malloc_str_tab(char **new_argv, char *string, int nbr_word,
                        char separator)
{
    new_argv = malloc(sizeof(char *) * nbr_word + 1);
    if (!string || !new_argv)
        return NULL;
    for (int i = 0; i < nbr_word; i++) {
        if (!(new_argv[i] = malloc(lenght_word_in_string(string, separator)
            + 1)))
            return NULL;
        if ((string = next_word(string, separator)) == NULL)
            return NULL;
    }
    return new_argv;
}

int check_error(char **new_argv, int nbr_word)
{
    for (int i = 0; i < nbr_word; i++) {
        if (!new_argv)
            return 84;
        new_argv++;
    }
    return 0;
}

char **fill_newargv(char **new_argv, char *string, int nbr_word,
                        char separator)
{
    int x = 0;

    if (!new_argv || !string)
        return NULL;
    for (int i = 0; i < nbr_word; i++) {
        x = 0;
        for (; (string[0] == separator || string[0] == '\t')
            && string[0] != '\0'; string++);
        string = (string[0] == separator ||
            string[0] == '\t') ? string++ : string;
        for (; (string[0] != separator || string[0] == '\t')
            && string [0] != '\0'; x++, string++)
            new_argv[i][x] = string[0];
    }
    return new_argv;
}

char **put_str_in_tab_of_tab(char *string, char separator)
{
    int nbr_word = 0;
    char **new_argv = NULL;
    int to_malloc = 0;
    int x = 0;
    int w = 0;

    if (!string || (nbr_word = count_space(string, separator) + 1) == -1)
        return NULL;
    if (!(new_argv = malloc_str_tab(new_argv, string, nbr_word, separator)))
        return NULL;
    if (!(new_argv = fill_newargv(new_argv, string, nbr_word, separator)))
        return NULL;
    if (check_error(new_argv, nbr_word) == 84)
        return NULL;
    return new_argv;
}
