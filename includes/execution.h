/*
** execution.h for 42sh in /home/pierre/PSU/PSU_2016_42sh
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Thu May 11 16:21:18 2017 Pierre J. Alderman
** Last update Sun May 21 23:08:37 2017 Senpai
*/

#ifndef EXECUTION_H_
# define EXECUTION_H_

#include "parser.h"
#include "utils.h"

typedef int (*t_exec_state)(char **, t_command **, char **);

#define EXEC_NB_STATES 7
#define EXEC_ERROR 84

typedef struct	s_exec_state_desc
{
  t_exe_state	state;
  t_exec_state	func;
}		t_exec_state_desc;

char	***take_pipe_command(t_command *);
char	**list_to_tab(t_arg *arg);
t_exec_state_desc	*get_states();
int	exec_commands(t_command *commands, char **envp,
		      int exe, t_exec_state_desc *states);
int	or_command(char **args, t_command **commands, char **envp);
int	and_command(char **args, t_command **commands, char **envp);
int	exec_reg(char **args, t_command **commands, char **envp);
int	pipe_command(char **args, t_command **commands, char **envp);
int	fork_exec(char **args, char **envp);
int	count_pipe(t_command *command);
int	exec_pipe(char ***cmd);
int	redirect_l(char **args, t_command **commands, char **envp);
int	redirect_l_l(char **args, t_command **commands, char **envp);
int	redirect_l_l_r(char **args, t_command **commands, char **envp);
int	redirect_l_l_r_r(char **args, t_command **commands, char **envp);
int	check_redirect_r(char **args, t_command **commands, char **envp);
int	redirect_r(char **args, t_command **commands, char **envp);
int	redirect_r_l(char **args, t_command **commands, char **envp);
int	redirect_r_l_l(char **args, t_command **commands, char **envp);
int	redirect_r_r_l(char **args, t_command **commands, char **envp);
int	redirect_r_r(char **args, t_command **commands, char **envp);
int	redirect_r_r_l_l(char **args, t_command **commands, char **envp);
int	check_redirect_l_l(char **args, t_command **commands, char **envp);
int     check_redirect_r_r(char **args, t_command **commands, char **envp);
int	my_strcmp(char *, char *);
char	*my_strcat(char *, char *);

#endif /* EXECUTION_H_ */
