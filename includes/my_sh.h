/*
** EPITECH PROJECT, 2022
** my_sh
** File description:
** header
*/

#ifndef MY_SH_H_
    #define MY_SH_H_

    #include <stdio.h>
    #include <unistd.h>
    #include "lib.h"
    #include <errno.h>
    #include <sys/types.h>
    #include <sys/wait.h>

    int get_line(int argc, char **argv, char **env);
    int my_sh(int argc, char **argv, char **env);
    int check_cmd(char *sentence, char **env, char **all_paths);
    char **put_str_in_tab_of_tab(char *string, char separator);
    char *my_strcat(char *src, char *dest);
    int lenght_new_word(char *sentence, char separator);
    char *get_firstword(char *sentence, char separator);
    char **calls_path_env(char **env);
    int display_env(char **env);
    int my_cd(char *new_word, char **new_tab, char **env);
    char **my_setenv(char **env, char *sentence);
    char *change_sentence(char *sentence);

typedef struct str_tab {
    int space;
    char **new_argv;
    int to_malloc;
    int w;
    int x;
    char *path;
} str_tab_t;

#endif
