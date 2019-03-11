/*
** memdup.c for 42sh in /home/pierre/PSU/PSU_2016_42sh
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Thu May 18 19:14:51 2017 Pierre J. Alderman
** Last update Tue May 30 19:04:42 2017 Matthias Gayaud
*/

#include "utils.h"

void	*memdup(void *p, size_t b)
{
  void	*d;

  if ((d = malloc(b)) == NULL)
    return (NULL);
  d = memcpy(d, p, b);
  return (d);
}
