/*
** find_in_env.c for 42sh in /home/zahut/rendu/PSU/PSU_2016_42sh/src/builtins
** 
** Made by Thibault Hebert
** Login   <thibault.hebert@epitech.eu>
** 
** Started on  Thu Apr 27 11:46:13 2017 Thibault Hebert
** Last update Mon May 15 14:06:56 2017 Pierre J. Alderman
*/

#include "builtins.h"

t_evar		*find_in_env(char *name, t_evar *env)
{
  t_evar	*tmp;

  tmp = env;
  while (strcmp(tmp->name, name) != SUCESS)
    {
      if (tmp->next == NULL)
	return (NULL);
      tmp = tmp->next;
    }
  return (tmp);
}
