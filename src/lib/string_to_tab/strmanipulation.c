/*
** EPITECH PROJECT, 2022
** lib
** File description:
** lenghtword
*/

#include "my_sh.h"

int lenght_word_in_string(char *string, char separator)
{
    int count = 0;

    if (!string)
        return -1;
    for (int i = 0; string[i] != separator && string[i] != '\0'; i++, count++);
    return count + 1;
}

char *next_word(char *string, char separator)
{
    if (!string)
        return NULL;
    for (int i = 0; string[i] == separator && string[i] != '\0'; string++);
    for (int i = 0; string[i] != separator && string[i] != '\0'; string++);
    while (string[0] == separator)
        string++;
    return string;
}
