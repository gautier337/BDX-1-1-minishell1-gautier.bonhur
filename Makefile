##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Gautier BONHUR
##

NAME			=	mysh

SRC_MAIN		= main.c

SRC				=	$(addprefix src/, \
					lib/my_putchar.c \
					lib/my_putstr.c \
					lib/string_to_tab/maintab.c \
					lib/string_to_tab/strmanipulation.c \
					lib/my_strcat.c \
					lib/my_strcmp.c \
					lib/my_strlen.c \
					lib/space_and_word.c \
					manage_bin/bin_path.c \
					mysh.c \
					usefull/get_line.c \
					usefull/get_words_sentences.c \
					builtins/cd.c \
					builtins/env.c \
					builtins/setenv.c \
					usefull/change_sentence.c \
					check_command/check_cmd.c)

SRC_TESTS = tests/tests_main.c

OBJ				=			$(SRC:.c=.o)

OBJ_MAIN		=			$(SRC_MAIN:.c=.o)

CFLAGS 			= 			-I./includes

CRITERION		= 			--coverage -lcriterion

all: 			$(NAME)

$(NAME):		$(OBJ) $(OBJ_MAIN)
	gcc -o $(NAME) $(OBJ) $(OBJ_MAIN) $(LDFLAGS)
	make clean

tests_run: $(OBJ)
	make re
	gcc -o unit_tests $(SRC) $(SRC_TESTS) $(CFLAGS) $(CRITERION)
	./unit_tests
	rm unit_tests

clean:
	rm -f $(OBJ)
	rm -f *.o
	rm -f *.gcda
	rm -f *.gcno

fclean:			clean
	rm -f $(NAME)

re:			$(NAME)

.PHONY: fclean tests_run clean re make