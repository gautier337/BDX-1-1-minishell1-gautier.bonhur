/*
** EPITECH PROJECT, 2022
** convert \t in \n
** File description:
** minishell
*/

#include "my_sh.h"

char *change_sentence(char *sentence)
{
    int i = 0;
    int last_letter = 0;

    if (!sentence)
        return NULL;
    for (; sentence[i] != '\0'; i++) {
        if (sentence[i] == '\t')
            sentence[i] = ' ';
        if (sentence[i] != ' ' && sentence[i] != '\t'
            && sentence[i] != '\0' && sentence[i] != '\n')
            last_letter = i;
    }
    sentence[last_letter + 1] = '\n';
    sentence[last_letter + 2] = '\0';
    return sentence;
}
