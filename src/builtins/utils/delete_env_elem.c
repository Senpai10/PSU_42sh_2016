/*
** delete_env_elem.c for 42sh in /home/zahut/rendu/PSU/PSU_2016_42sh/src/builtins
** 
** Made by Thibault Hebert
** Login   <thibault.hebert@epitech.eu>
** 
** Started on  Sun Apr 30 21:01:53 2017 Thibault Hebert
** Last update Mon May 15 15:30:09 2017 Pierre J. Alderman
*/

#include "builtins.h"

void	free_env_elem(t_evar *tmp, int flag)
{
  my_free(tmp->data);
  my_free(tmp->name);
  if (flag == LAST_ELEM)
    tmp->prev->next = NULL;
  else if (flag == FIRST_ELEM)
    tmp->next->prev = NULL;
  else
    {
      tmp->next->prev = tmp->prev;
      tmp->prev->next = tmp->next;
    }
}

void	delete_env_elem(t_evar *tmp, t_evar *env)
{
  if (tmp == take_last_elem(env))
    free_env_elem(tmp, LAST_ELEM);
  else if (tmp == env)
    {
      env = env->next;
      free_env_elem(tmp, FIRST_ELEM);
    }
  else
    free_env_elem(tmp, NORMAL_ELEM);
}
