##
## Makefile for 42sh in /home/pierre/PSU/PSU_2016_42sh/src/parser
## 
## Made by Pierre J. Alderman
## Login   <pierre@epitech.net>
## 
## Started on  Thu Apr 27 13:55:22 2017 Pierre J. Alderman
## Last update Thu May 11 14:32:33 2017 Pierre J. Alderman
##

NAME	=	parser

SRCS	=	test_main.c	\
		parser.c	\
		init_t_command.c	\
		states/add_arg.c	\
		states/add_command.c	\
		states/browse.c		\
		states/catch_litteral_str.c	\
		states/check_double_op.c	\
		states/init_t_arg.c	\
		states/catch_str.c	\
		states/wild_card.c	\
		states/catch_parenthesis.c	\
		states/add_home.c	\
		states/semicolon.c	\
		states/p_add_token.c	\
		states/p_end_of_digest.c	\
		states/p_unexpected_token.c	\
		states/p_pipe_or_or.c	\
		states/p_job_or_and.c	\
		states/p_l_redir.c	\
		states/p_r_redir.c	\
		../utils/do_free.c	\
		../utils/burn_arg.c	\
		../utils/su_cat.c	\
		../utils/burn_commands.c	\
		../utils/do_malloc.c		\
		print_commands.c	\

CFLAGS	+=	-I../../includes/	\
		-Wall -Wextra -Werror	\
		-g3			\
##		-O3			\

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(SRCS) $(CFLAGS)

fclean:
	rm -f $(NAME)

re: fclean all
