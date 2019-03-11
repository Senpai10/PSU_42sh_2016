/*
** my_exit.c for 42sh in /home/zahut/rendu/PSU/PSU_2016_42sh/src/builtins
** 
** Made by Thibault Hebert
** Login   <thibault.hebert@epitech.eu>
** 
** Started on  Sun Apr 30 21:59:24 2017 Thibault Hebert
** Last update Mon May 22 00:02:30 2017 Thibault Hebert
*/

#include "builtins.h"

int	my_exit(char **command, t_env *env)
{
  if (command[1] == NULL)
    {
      printf("exit\n");
      my_free_env(ENV);
      exit(0);
    }
  else if (command[2] != NULL)
    {
      fprintf(stderr, "%s: Expression Syntax.\n", command[0]);
      return (EXEC_ERROR);
    }
  else
    {
      if (my_str_isnum(command[1]) == SUCESS)
	{
	  printf("exit\n");
	  exit(atoi(command[1]));
	}
      else
	fprintf(stderr, "%s: Expression Syntax.\n", command[0]);
    }
  return (SUCESS);
}
