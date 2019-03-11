/*
** my.h for lib in /home/Senpai/Fonction utile
** 
** Made by Charly DAI
** Login   <Senpai@epitech.net>
** 
** Started on  Thu Dec 15 22:21:50 2016 Charly DAI
** Last update Tue May 30 18:11:46 2017 Matthias Gayaud
*/

#ifndef MY_H_
# define MY_H_

#include "source.h"
#include "builtins.h"
#include "ftsh.h"
#include "input.h"
#include "my.h"
#include "parser.h"

#define EXEC_ERROR 84
#define EXEC_SUCCESS 0

typedef	struct	s_ret
{
  char		**command;
  char		**redirec;
  t_command	*commands;
  t_exe_state	parser_state;
}		t_ret;

int	my_get_nbr(const char *str);
void	my_putchar(char c);
void	my_put_nbr(int nb);
char	*my_revstr(char *str);
char	*my_strcpy(char *dest, const char *src);
ssize_t	read(int fd, void *buf, size_t count);
void	free(void *ptr);
pid_t	wait(int *status);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int n);
char	*get_next_line(const int fd);
char	**my_str_to_wordtab(char *str, char c);
char	**my_str_to_wordtab_path(char *str);
void	*malloc(size_t size);
char	*my_strcat(char *, char *);
void	my_printf(char *format, ...);
/* int	fork_exec(t_ret *mysh, char **envp, int *signal); */
int	nb_line_env(char **env);
char	**backup_env(t_ret *mysh);
char	*my_strdup(char *str);
char	**list_to_tab(t_arg *);
int	execvpe(const char *file, char *const argv[], char *const envp[]);
void	perror(const char *str);
int	list_len_command(t_arg *);

#endif /* !MY_H */
