/*
** my_strncmp.c for lib in /home/thibault/CPool_Day07/lib/my
** 
** Made by thibault hebert
** Login   <thibault@epitech.net>
** 
** Started on  Wed Oct 12 18:50:27 2016 thibault hebert
** Last update Wed May  3 15:07:59 2017 Thibault Hebert
*/

#include "source.h"

int	my_strncmp(char *s1, char *s2, int n)
{
  int	it;

  it = 0;
  while (it < n)
    {
      if (s1[it] != s2[it])
	return (ERROR);
      it++;
    }
  return (SUCESS);
}
