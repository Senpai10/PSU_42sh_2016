/*
** take_last_elem.c for 42sh in /home/zahut/rendu/PSU/PSU_2016_42sh/src/builtins
** 
** Made by Thibault Hebert
** Login   <thibault.hebert@epitech.eu>
** 
** Started on  Sun Apr 30 20:32:27 2017 Thibault Hebert
** Last update Mon May 15 15:49:26 2017 Pierre J. Alderman
*/

#include "builtins.h"

t_evar		*take_last_elem(t_evar *env)
{
  t_evar	*tmp;

  tmp = env;
  while (tmp->next != NULL)
    tmp = tmp->next;
  return (tmp);
}
