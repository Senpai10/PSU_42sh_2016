/*
** create_elem.c for 42sh in /home/zahut/rendu/PSU/PSU_2016_42sh/src/builtins
** 
** Made by Thibault Hebert
** Login   <thibault.hebert@epitech.eu>
** 
** Started on  Sun Apr 30 20:21:47 2017 Thibault Hebert
** Last update Mon May 15 15:41:44 2017 Pierre J. Alderman
*/

#include "builtins.h"

int		add_new_elem(char *name, char *data, t_evar *env)
{
  t_evar	*tmp;

  if ((tmp = malloc(sizeof(*tmp))) == NULL)
    return (EXEC_ERROR);
  if ((tmp->name = strdup(name)) == NULL)
    return (EXEC_ERROR);
  if (data == NULL)
    {
      if ((tmp->data = malloc(sizeof(char) * 1)) == NULL)
	return (EXEC_ERROR);
      tmp->data[0] = '\0';
    }
  else if ((tmp->data = strdup(data)) == NULL)
    return (EXEC_ERROR);
  tmp->prev = take_last_elem(env);
  tmp->prev->next = tmp;
  tmp->next = NULL;
  return (SUCESS);
}
