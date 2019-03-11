/*
** prompt.c for 42sh in /home/zahut/rendu/PSU/PSU_2016_42sh
** 
** Made by Thibault Hebert
** Login   <thibault.hebert@epitech.eu>
** 
** Started on  Thu May  4 15:43:55 2017 Thibault Hebert
** Last update Wed May 31 09:18:47 2017 Matthias Gayaud
*/

#include "source.h"

int	run(t_env *env, t_ret *mysh)
{
  int	ret;

  ret = 0;
  ret = check_builtins(mysh->command, env);
  if (ret == EXEC_ERROR)
    return (EXIT_FAILURE);
  else if (ret == ERROR)
    return (ERROR);
  else
    return (SUCESS);
}

int	prompt(t_env *env, t_ret *mysh)
{
  int	ret;

  ret = 0;
  if ((mhsh->env = env_to_tab(env)) == NULL)
    return (EXEC_ERROR);
  while (1)
    {
      my_putstr("42sh>");
      if ((mysh->line = get_input(0)) == NULL)
	{
	  my_putstr("exit\n");
	  return (ret);
	}
      if ((mysh->commands = parser(mysh->line, mysh->env)) == NULL)
	return (EXEC_ERROR);
      if ((my->command = list_to_tab(mysh->command->args)) == NULL)
	return (EXEC_ERROR);
      if ((ret = run(env, mysh)) == EXEC_ERROR)
	return (EXIT_FAILURE);
      else if (ret == ERROR)
	ret = fork_exec(mysh, mysh->env);
    }
  return (ret);
}
