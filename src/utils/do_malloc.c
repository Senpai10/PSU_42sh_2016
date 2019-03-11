/*
** do_malloc.c for 42sh in /home/pierre/PSU/PSU_2016_42sh/src/curs
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Tue May  2 22:38:46 2017 Pierre J. Alderman
** Last update Tue May 30 19:04:17 2017 Matthias Gayaud
*/

#include "utils.h"

void		*do_malloc(size_t size)
{
  char		*ptr;
  size_t	i;

  ptr = malloc(size);
  if (ptr == NULL)
    return (NULL);
  i = 0;
  while (i < size)
    ptr[i++] = 0;
  return ((void *)ptr);
}
