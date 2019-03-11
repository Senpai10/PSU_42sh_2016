/*
** builtins.h for 42sh in /home/zahut/rendu/PSU/PSU_2016_42sh/src/builtins
** 
** Made by Thibault Hebert
** Login   <thibault.hebert@epitech.eu>
** 
** Started on  Thu Apr 27 11:54:46 2017 Thibault Hebert
** Last update Tue May 30 18:09:59 2017 Matthias Gayaud
*/

#ifndef BUILTINS_H_
# define BUILTINS_H_

#include "utils.h"

#define BUILTINS_ERROR (1)
#define FIRST_ELEM (1)
#define LAST_ELEM (2)
#define NORMAL_ELEM (0)
#define EXIT_SUCESS (0)
#define SUCESS (0)
#define ERROR (-1)

#define ENVP env->envp

#define ENV env->env

typedef struct	s_echo_opt
{
  int		e;
  int		E;
  int		n;
  int		jump;
}		t_echo_opt;

char	**env_to_tab(t_evar *);
int	my_str_isnum(char *);
t_evar	*take_last_elem(t_evar *);
char	*my_strcat(char *, char *);
t_evar	*find_in_env(char *, t_evar *);
int	exec_cd(t_evar *, char **);
int	exec_cd2(t_evar *env , char *, char *);
void	display_env(t_evar *);
int	my_strisnum(char *);
void	my_free_env(t_evar *);
void	my_free(void *);
int	add_new_elem(char *, char *, t_evar *);
void	delete_env_elem(t_evar *, t_evar *);
t_evar	*take_env(char **);
int	check_is_builtins(char **, t_env *);
int	check_builtins(char **, t_env *);
void	my_free_tab(char **);
char	*create_pwd(char *);
char	*create_home(char *);
char	*take_username();
t_evar	*create_env();
int	check_cd(t_evar *, char **);
char	**get_kv(char *str);
int	my_cd(t_env *, char **);
int	my_exit(char **, t_env *);
int	my_unsetenv(t_env *, char **);
int	my_setenv(t_env *, char **);
int	my_env(t_env *, char **);
int	export(t_env *env, char **args);
int	alias(t_env *env, char **args);

int	ftsh_echo(char **args);

#endif /* BUILTINS_H */
