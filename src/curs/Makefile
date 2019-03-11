##
## Makefile for 42sh in /home/Matthy/PSU_2016_42sh/src/curs
## 
## Made by Matthias Gayaud
## Login   <Matthy@epitech.net>
## 
## Started on  Thu May  4 19:15:39 2017 Matthias Gayaud
## Last update Sun May 21 22:43:10 2017 Matthias Gayaud
##

SRC	=	get_input.c		\
		add_token.c		\
		auto_complete.c		\
		del_token.c		\
		free_params.c		\
		free_states.c		\
		init_machine_params.c	\
		input_switcher.c	\
		mv_curs.c		\
		mv_curs_l.c		\
		mv_curs_r.c		\
		return_str.c		\
		try_exit.c		\
		prev_str.c		\
		next_str.c		\
		skip_state.c		\
		get_pressed_key.c	\
		../utils/insert_char.c	\
		../utils/my_putstr.c	\
		../utils/del_char.c	\
		../utils/do_free.c	\
		../utils/do_malloc.c	\
		../utils/my_strlen.c	\


OBJ	=	$(SRC:.c=.o)

NAME	=	42sh_test

CFLAGS	+=	-W -Wall -Wextra -lncurses -Iinclude -g3

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all
