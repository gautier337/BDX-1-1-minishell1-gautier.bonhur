/*
** EPITECH PROJECT, 2022
** get_word_sentences
** File description:
** get_words_sentences
*/

#include "my_sh.h"

int lenght_new_word(char *sentence, char separator)
{
    int lenght_new_word = 0;
    int i = 0;

    if (!sentence)
        return -1;
    for (;sentence[0] == separator && sentence[0] != '\0'; sentence++);
    for (;sentence[0] != separator && sentence[1] != '\0';
        lenght_new_word++, sentence++);
    return lenght_new_word;
}

char *get_firstword(char *sentence, char separator)
{
    char *new_word = NULL;
    int to_malloc = 0;

    if (!sentence)
        return NULL;
    if ((to_malloc = lenght_new_word(sentence, separator)) == -1)
        return NULL;
    new_word = malloc(to_malloc + 1);
    for (;sentence[0] == separator && sentence[0] != '\0'; sentence++);
    for (int i = 0; sentence[0] != ' '
        && sentence[1] != '\0'; sentence++, i++)
        new_word[i] = sentence[0];
    new_word[to_malloc] = '\0';
    if (!new_word)
        return NULL;
    return new_word;
}
