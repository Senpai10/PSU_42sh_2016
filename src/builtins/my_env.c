/*
** my_env.c for 42sh  in /home/zahut/rendu/PSU/PSU_2016_42sh/src/builtins
** 
** Made by Thibault Hebert
** Login   <thibault.hebert@epitech.eu>
** 
** Started on  Thu Apr 27 16:18:53 2017 Thibault Hebert
** Last update Mon May 22 00:02:54 2017 Thibault Hebert
*/

#include "builtins.h"

int	my_env(t_env *env, char **command)
{
  if (command[1] == NULL)
    {
      display_env(ENV);
      return (SUCESS);
    }
  else
    {
      fprintf(stderr, "%s: '%s': No such file or directory\n",
	      command[0], command[1]);
      return (BUILTINS_ERROR);
    }
  return (SUCESS);
}
