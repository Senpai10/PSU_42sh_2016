/*
** do_free.c for 42sh in /home/pierre/PSU/PSU_2016_42sh/src/parser
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Wed Apr 26 19:53:48 2017 Pierre J. Alderman
** Last update Sat May 20 14:03:42 2017 Matthias Gayaud
*/

#include "source.h"

int	do_free(void **p)
{
  if (!p)
    return (0);
  if (!*p)
    return (0);
  free(*p);
  *p = NULL;
  return (1);
}
