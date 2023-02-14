/*
** EPITECH PROJECT, 2022
** count_space
** File description:
** count_space_of_a_string
*/

#include "lib.h"

int count_space(char *string, char separator)
{
    int space = 0;

    if (!string)
        return -1;
    for (int i = 0; i < my_strlen(string); i++)
        if (string[i] == separator && string[i + 1] != separator) {
            space++;
            i++;
        }
    return space;
}

char *forward_sentence_first_word(char *sentence, char separator)
{
    if (!sentence)
        return NULL;
    while ((sentence[0] == separator || sentence[0] == '\t')
        && sentence[0] != '\0')
        sentence++;
    return sentence;
}
