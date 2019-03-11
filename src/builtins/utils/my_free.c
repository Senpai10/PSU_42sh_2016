/*
** my_free.c for 42sh in /home/zahut/rendu/PSU/PSU_2016_42sh/src/builtins
** 
** Made by Thibault Hebert
** Login   <thibault.hebert@epitech.eu>
** 
** Started on  Sun Apr 30 21:08:40 2017 Thibault Hebert
** Last update Mon May 22 00:02:25 2017 Thibault Hebert
*/

#include "builtins.h"

void		my_free_env(t_evar *env)
{
  t_evar	*tmp;

  tmp = env;
  while (tmp != NULL)
    {
      my_free(tmp->data);
      my_free(tmp->name);
      tmp = tmp->next;
    }
}

void	my_free_tab(char **p)
{
  int	it;

  it = 0;
  while (p[it] != '\0')
    {
      free(p[it]);
      p[it] = NULL;
      it++;
    }
}

void	my_free(void *elem)
{
  free(elem);
  elem = NULL;
}
