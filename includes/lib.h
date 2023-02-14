/*
** EPITECH PROJECT, 2022
** lib
** File description:
** header
*/

#ifndef LIB_H_
    #define LIB_H_

    #include <stdlib.h>

    void my_putstr (char const *str);
    int my_strlen (char const *str);
    void my_putchar(char c);
    int my_strcmp (char const *s1, char const *s2);
    char **put_str_in_tab_of_tab(char *string, char seperator);
    int count_space(char *string, char separator);
    char *next_word(char *string, char separator);
    int lenght_word_in_string(char *string, char separator);
    char *forward_sentence_first_word(char *sentence, char separator);

#endif