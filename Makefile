##
## Makefile for 42sh in /home/pierre/PSU/PSU_2016_42sh
## 
## Made by Pierre J. Alderman
## Login   <pierre@epitech.net>
## 
## Started on  Sun May 21 18:52:46 2017 Pierre J. Alderman
## Last update Tue May 30 20:21:34 2017 Matthias Gayaud
## Last update Tue May 30 16:07:05 2017 Pierre J. Alderman
##

GCC     =	gcc

CP      =	cp

RM      =	rm -f

CFLAGS  =	-W -Wall -Wextra -Iincludes/ -lncurses

SRC     =	ftsh.c						\
		main.c						\
		src/ftsh/init_ftsh.c				\
		src/ftsh/exec_from_file.c			\
		src/builtins/check_is_builtins.c	 	\
	  	src/builtins/exec_cd.c  	      		\
	  	src/builtins/my_cd.c       			\
	  	src/builtins/my_env.c   			\
	  	src/builtins/my_exit.c   			\
	  	src/builtins/my_setenv.c    			\
	  	src/builtins/my_strcat.c 			\
	  	src/builtins/my_unsetenv.c		       	\
		src/builtins/take_env.c				\
		src/builtins/alias.c				\
		src/builtins/export.c				\
		src/builtins/echo.c				\
	  	src/builtins/utils/add_new_elem.c    		\
		src/builtins/utils/create_env.c			\
	  	src/builtins/utils/delete_env_elem.c 		\
	  	src/builtins/utils/display_env.c 		\
	  	src/builtins/utils/env_to_tab.c 		\
		src/builtins/utils/find_in_env.c		\
	  	src/builtins/utils/get_env_info.c		\
	  	src/builtins/utils/my_free.c			\
	  	src/builtins/utils/my_str_isnum.c		\
	  	src/builtins/utils/take_last_elem.c		\
		src/execution/exec.c				\
		src/execution/exec_pipe.c			\
		src/execution/list_to_tab.c			\
		src/execution/check_redirect.c			\
		src/execution/redirect_r.c			\
		src/execution/redirect_r_l.c			\
		src/execution/redirect_r_l_l.c			\
		src/execution/redirect_r_r.c			\
		src/execution/redirect_r_r_l.c			\
		src/execution/redirect_r_r_l_l.c		\
		src/execution/redirect_l.c			\
		src/execution/redirect_l_l.c			\
		src/execution/redirect_l_l_r.c			\
		src/execution/redirect_l_l_r_r.c		\
		src/execution/exec_reg.c			\
		src/execution/get_states.c			\
		src/execution/take_pipe_command.c		\
		src/execution/exec_commands.c			\
		src/execution/pipe_command.c			\
		src/execution/consume_command.c			\
		src/execution/or_and.c				\
		src/parser/parser.c				\
		src/parser/init_t_command.c			\
		src/parser/states/add_arg.c			\
		src/parser/states/add_command.c			\
		src/parser/states/browse.c 			\
		src/parser/states/catch_litteral_str.c		\
		src/parser/states/exit_state.c			\
		src/parser/states/init_t_arg.c			\
		src/parser/states/catch_str.c			\
		src/parser/states/wild_card.c			\
		src/parser/states/catch_parenthesis.c		\
		src/parser/states/add_home.c			\
		src/parser/states/semicolon.c			\
		src/parser/print_commands.c			\
		src/parser/states/p_add_token.c			\
		src/parser/states/p_end_of_digest.c		\
		src/parser/states/p_unexpected_token.c		\
		src/parser/states/p_pipe_or_or.c		\
		src/parser/states/p_job_or_and.c		\
		src/parser/states/p_l_redir.c			\
		src/parser/states/p_r_redir.c			\
		src/parser/states/p_get_alias.c			\
		src/parser/states/p_append_command.c		\
		src/parser/states/p_ignore.c			\
		src/utils/do_free.c				\
		src/utils/do_malloc.c				\
		src/utils/burn_arg.c				\
		src/utils/su_cat.c				\
		src/utils/burn_commands.c			\
		src/utils/get_next_line.c			\
		src/utils/my_strncmp.c				\
		src/utils/my_strlen.c				\
		src/utils/my_strcmp.c				\
		src/utils/my_putstr.c				\
		src/utils/my_puttab.c				\
		src/utils/take_path.c				\
		src/utils/memdup.c				\
		src/utils/my_str_to_word_tab.c			\
		src/curs/get_input.c				\
		src/curs/skip_state.c				\
		src/curs/add_token.c				\
		src/curs/auto_complete.c			\
		src/curs/del_token.c				\
		src/curs/try_exit.c				\
		src/curs/mv_curs_r.c				\
		src/curs/mv_curs_l.c				\
		src/curs/prev_str.c				\
		src/curs/next_str.c				\
		src/curs/init_machine_params.c			\
		src/curs/input_switcher.c			\
		src/curs/free_params.c				\
		src/curs/mv_curs.c				\
		src/curs/return_str.c				\
		src/curs/get_pressed_key.c			\
		src/utils/del_char.c				\
		src/utils/insert_char.c				\
		src/utils/tablen.c				\

OBJ     = 	$(SRC:.c=.o)

NAME    = 	42sh

all:	$(NAME)

$(NAME):	$(OBJ)
	$(GCC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:  fclean all
