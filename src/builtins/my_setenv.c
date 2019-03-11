/*
** my_setenv.c for 42sh in /home/zahut/rendu/PSU/PSU_2016_42sh/src/builtins
** 
** Made by Thibault Hebert
** Login   <thibault.hebert@epitech.eu>
** 
** Started on  Sun Apr 30 20:19:35 2017 Thibault Hebert
** Last update Mon May 15 15:53:13 2017 Pierre J. Alderman
*/

#include "builtins.h"

int		test_replace(t_evar *env, char **command)
{
  t_evar	*tmp;

  if ((tmp = find_in_env(command[1], env)) == NULL)
    return (ERROR);
  else
    {
      if (command[2] == NULL)
	{
	  if ((tmp->data = strdup("\0")) == NULL)
	    return (EXEC_ERROR);
	}
      else
	{
	  if ((tmp->data = strdup(command[2])) == NULL)
	    return (EXEC_ERROR);
	}
    }
  return (SUCESS);
}

int	my_setenv(t_env *env, char **command)
{
  int	ret;

  ret = 0;
  if (command[1] == NULL)
    {
      display_env(ENV);
      return (SUCESS);
    }
  if ((ret = test_replace(ENV, command)) == SUCESS)
    return (SUCESS);
  else if (ret == EXEC_ERROR)
    return (EXEC_ERROR);
  else if (command[2] == NULL)
    {
      if ((add_new_elem(command[1], NULL, ENV)) == EXEC_ERROR)
	return (EXEC_ERROR);
    }
  else if ((add_new_elem(command[1], command[2], ENV)) == EXEC_ERROR)
    return (EXEC_ERROR);
  return (SUCESS);
}
