/*
** my_puttab.c for 42sh in /home/zahut/rendu/PSU/PSU_2016_42sh/src/utils
** 
** Made by Thibault Hebert
** Login   <thibault.hebert@epitech.eu>
** 
** Started on  Sat May 13 13:14:59 2017 Thibault Hebert
** Last update Mon May 22 01:02:08 2017 Thibault Hebert
*/

#include "utils.h"

void	my_puttab(char **p)
{
  int	it;

  it = 0;
  while (p[it] != NULL)
    {
      printf("%s\n", p[it]);
      it++;
    }
}
