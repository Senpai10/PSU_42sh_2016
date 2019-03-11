/*
** my_unsetenv.c for 42sh in /home/zahut/rendu/PSU/PSU_2016_42sh/src/builtins
** 
** Made by Thibault Hebert
** Login   <thibault.hebert@epitech.eu>
** 
** Started on  Sun Apr 30 20:48:01 2017 Thibault Hebert
** Last update Mon May 15 15:30:24 2017 Pierre J. Alderman
*/

#include "builtins.h"

int		check_name_exist(char *name, t_evar *env)
{
  t_evar	*tmp;

  tmp = env;
  while (tmp != NULL)
    {
      if (strncmp(name, tmp->name, strlen(tmp->name)) == SUCESS)
	{
	  delete_env_elem(tmp, env);
	  return (SUCESS);
	}
      tmp = tmp->next;
    }
  return (SUCESS);
}

int	my_unsetenv(t_env *env, char **command)
{
  int	it;

  it = 1;
  if (command[1] == NULL)
    {
      fprintf(stderr, "%s: Too few arguments.\n", command[0]);
      return (BUILTINS_ERROR);
    }
  else
    {
      while (command[it] != NULL)
	{
	  check_name_exist(command[it], ENV);
	  it++;
	}
    }
  return (SUCESS);
}
