/*
** EPITECH PROJECT, 2022
** check_cmd
** File description:
** minishell1
*/

#include "my_sh.h"

int my_command(char **all_paths, char *new_word, char **new_tab, char **env)
{
    int find = 0;

    if (execve(new_tab[0], new_tab, env) != - 1)
        return 0;
    for (int i = 0; all_paths[i] != NULL && find == 0; i++)
        if (execve(my_strcat(my_strcat(all_paths[i], "/"), new_word),
            new_tab, env) != -1)
            find = 1;
    if (find == 0) {
        my_putstr(new_word);
        my_putstr(": Command not found.\n");
    }
    return 0;
}

int call_basic_cmd(char *sentence, char *new_word, char **env,
                        char **all_paths)
{
    char **new_tab = NULL;
    int i = 1;
    int find = 0;

    if (!next_word)
        return 84;
    if ((new_tab = put_str_in_tab_of_tab(sentence, ' ')) == NULL)
        return 84;
    if (fork() == 0) {
        my_command(all_paths, new_word, new_tab, env);
        kill(getpid(), 9);
    }
    wait(&i);
    return 0;
}

int call_cmd(char *new_word, char *sentence, char **env, char **all_paths)
{
    char **new_tab = NULL;

    if (!(new_tab = put_str_in_tab_of_tab(sentence, ' ')))
        return 84;
    if (my_strcmp(new_word, "exit") == 1) {
        my_putstr("exit\n");
        exit(0);
        return 0;
    }
    if (my_strcmp(new_word, "env") == 1) {
        if (display_env(env) == 84)
            return 84;
        return 0;
    }
    if (my_cd(new_word, new_tab, env) == 1)
        return 0;
    if (call_basic_cmd(sentence, new_word, env, all_paths) == 84)
        return 84;
    return 0;
}

int check_cmd(char *sentence, char **env, char **all_paths)
{
    char *new_word = NULL;

    if (!(sentence = change_sentence(sentence)))
        return 84;
    if (!(sentence = forward_sentence_first_word(sentence, ' ')))
        return 84;
    if (!(new_word = get_firstword(sentence, ' ')))
        return 84;
    if (!new_word || !sentence || !env)
        return 84;
    sentence[my_strlen(sentence) - 1] = '\0';
    if (my_strlen(sentence) == 0)
        return 0;
    return call_cmd(new_word, sentence, env, all_paths);
}
