/*
** utils.h for 42sh in /home/pierre/PSU/PSU_2016_42sh/src/curs
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Wed May  3 16:44:56 2017 Pierre J. Alderman
<<<<<<< HEAD
** Last update Tue May 30 23:39:33 2017 Thibault Hebert
=======
<<<<<<< HEAD
** Last update Tue May 30 20:23:15 2017 Matthias Gayaud
=======
** Last update Tue May 30 16:06:22 2017 Pierre J. Alderman
>>>>>>> acf261301d8b7e425ca1266566dd4c93441b46f2
>>>>>>> 3d3f44d06accad8fd871cf277c0c654a06bf0776
*/

#ifndef UTILS_H_
# define UTILS_H_

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/wait.h>
#include <pwd.h>
#include <stdio.h>
#include <errno.h>
#include <term.h>
#include <termios.h>
//#include <ncurses/curses.h>

typedef enum	e_exec_state
  {
    NO_STATE = 0,
    STATE_REG,
    STATE_FINAL_COMMAND,
    STATE_PIPE,
    STATE_R_REDIR,
    STATE_L_REDIR,
    STATE_DR_REDIR,
    STATE_DL_REDIR,
    STATE_OR,
    STATE_AND
  }		t_exe_state;

typedef struct		s_arg
{
  char			*arg;
  struct s_arg		*prev;
  struct s_arg		*next;
}			t_arg;

/*
** commands contains the command entered.
** args contains every argument entered w/ the command.
** args_it is a pointer to the current argument being digested.
** state represent the state in which the command must be executed
a**	eg: pipe, redirection, ect...
*/
typedef struct		s_command
{
  char			*command;
  t_arg			*args;
  t_arg			*args_it;
  int			nb_args;
  t_exe_state		state;
  struct s_command	*next;
  struct s_command	*prev;
}			t_command;

typedef struct	s_evar
{
  char		*name;
  char		*data;
  struct s_evar	*next;
  struct s_evar	*prev;
}		t_evar;

typedef struct		s_alias
{
  char			*alias;
  char			*command;
  t_command		*p_command;
  struct s_alias	*prev;
  struct s_alias	*next;
}			t_alias;

typedef struct		s_namespace
{
  char			*key;
  char			*value;
  struct s_namespace	*prev;
  struct s_namespace	*next;
}			t_namespace;

typedef struct	s_env
{
  t_evar       	*env;
  char		**envp;
  t_alias	*alias;
  t_namespace	*lvar;
}		t_env;

#define EXEC_ERROR 84

char		*su_cat(char *s, char c);
int		do_free(void **p);
char		*insert_char(char *, char, int);
void		*do_malloc(size_t size);
void		my_putstr(char *str);
char		*del_char(char *str, int i);
char		*get_next_line(const int fd);
void		my_puttab(char **);
char		**take_path(char **);
t_command	*parser(char *to_digest, t_env *envp);
t_command	*consume_command(t_command *commands,
				 unsigned int step);
void		*memdup(void *p, size_t b);
void		my_putchar(char c);
void		burn_commands(t_command *commands);
int		execvpe(const char *file, char *const argv[],
			char *const envp[]);
int		my_strlen(char *str);
int		tablen(char **str);

#endif
/*
** UTILS_H_
*/
