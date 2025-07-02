##
## EPITECH PROJECT, 2025
## Corewar
## File description:
## THE Makefile
##

SRC	=	src/op.c	\
		src/head.c	\
		lib/my_strstr.c	\
		lib/binary_to_decimal.c	\
		lib/my_strcpy.c		\
		lib/my_memmove.c	\
		lib/my_strncpy.c		\
		lib/my_revstr.c		\
		lib/my_strcat.c		\
		lib/my_atoi.c		\
		lib/my_strcmp.c		\
		lib/my_strncmp.c	\
		lib/my_strdup.c		\
		lib/verifcation.c 	\
		lib/my_str_to_word_array.c	\
		\
		lib/miniprintf/mini_printf.c 	\
		lib/miniprintf/my_putchar.c 	\
		lib/miniprintf/my_put_nbr.c 	\
		lib/miniprintf/my_putstr.c 	\
		lib/miniprintf/my_strlen.c 	\
		\
		src/main.c 	\
		\
		src/parsing/check_argument/check_argument.c 	\
		src/parsing/check_file/check_file.c 	\
		src/parsing/free_warrior_info.c 	\
		src/arena/place_warriors/find_warrior.c \
		src/parsing/check_argument/is_enough_warrior.c 	\
		src/parsing/check_argument/fill_adresse.c 	\
		src/parsing/check_argument/fill_file.c 	\
		src/parsing/check_argument/fill_warrior_info.c 	\
		src/parsing/check_argument/set_nb_name.c 	\
		src/parsing/check_argument/fill_dump.c 	\
		src/parsing/check_argument/fill_nb_name.c 	\
		src/parsing/check_file/fill_warrior_cmd.c 	\
		src/parsing/parsing_utils/is_a_dot_cor.c 	\
		src/parsing/parsing_utils/is_int.c 	\
		\
		instructions/add.c	\
		instructions/aff.c	\
		instructions/and.c	\
		instructions/fork.c	\
		instructions/ld.c	\
		instructions/ldi.c	\
		instructions/lfork.c	\
		instructions/live.c	\
		instructions/lld.c	\
		instructions/lldi.c	\
		instructions/or.c	\
		instructions/st.c	\
		instructions/sti.c	\
		instructions/sub.c	\
		instructions/xor.c	\
		instructions/zjmp.c	\
		instructions/post_inst.c \
		\
		src/arena/free_arena.c 	\
		src/arena/arena_utils/clean_arena.c 	\
		src/arena/arena_utils/read_coding_byte.c 	\
		src/arena/init_arena/init_arena.c 	\
		src/arena/place_warriors/place_warriors.c 	\
		src/arena/place_warriors/get_equidistance.c	\
		\
		src/csfml_bonus/graphical.c	\
		src/csfml_bonus/log.c

OBJ		=	$(SRC:.c=.o)

CC		=	gcc

CFLAGS	=	-W -Wall -Wextra -std=gnu11 -I./include

BONUS_FLAGS	= -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window -Ofast

TEST_FLAGS 	=	-g -DTEST --coverage -lgcov -lcriterion

NAME	=	corewar

all: $(NAME)

%.o:	%.c
	$(CC)	$(CFLAGS)	-c $<	-o $@

$(NAME):	$(OBJ)
	$(CC)	$(CFLAGS)	$(OBJ) $(BONUS_FLAGS)	-o	$(NAME)


debug: CFLAGS += -DDEBUG
debug: fclean $(NAME)

bonus: CFLAGS += -DBONUS_FLAGS -g
bonus: fclean $(NAME)

clean:
	rm -f $(OBJ)
	rm -f $(SRC:.c=.gcno)
	rm -f $(SRC:.c=.gcda)
	rm -rf *.gc*
	rm -rf *.cor

fclean: clean
	rm -f $(NAME)

re: fclean all
