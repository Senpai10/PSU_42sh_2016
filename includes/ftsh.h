/*
** ftsh.h for 42sh in /home/pierre/PSU/PSU_2016_42sh
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Wed May  3 17:36:18 2017 Pierre J. Alderman
** Last update Tue May 30 18:05:23 2017 Matthias Gayaud
*/

#ifndef FTSH_H_
# define FTSH_H_

#include "utils.h"
#include "input.h"
#include "parser.h"
#include "builtins.h"
#include "execution.h"

int	start_ftsh(char **envp);
int	init_ftsh(t_env *env, char **envp,
		  t_exec_state_desc *states);
int    	exec_from_file(FILE *fd,
		       t_env *env, char **envp,
		       t_exec_state_desc *states);
char	*get_input();

#endif
/*
** FTSH_H_
*/
