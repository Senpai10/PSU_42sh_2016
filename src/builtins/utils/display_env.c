/*
** display_env.c for 42sh in /home/zahut/rendu/PSU/PSU_2016_42sh/src/builtins
** 
** Made by Thibault Hebert
** Login   <thibault.hebert@epitech.eu>
** 
** Started on  Thu Apr 27 16:20:20 2017 Thibault Hebert
** Last update Mon May 15 15:45:41 2017 Pierre J. Alderman
*/

#include "builtins.h"

void		display_reverse_env(t_evar *env)
{
  t_evar	*tmp;

  tmp = take_last_elem(env);
  while (tmp != NULL)
    {
      printf("%s=%s\n", tmp->name, tmp->data);
      tmp = tmp->prev;
    }
}

void	display_env(t_evar *env)
{
  t_evar	*tmp;

  tmp = env;
  while (tmp != NULL)
    {
      printf("%s=%s\n", tmp->name, tmp->data);
      tmp = tmp->next;
    }
}
