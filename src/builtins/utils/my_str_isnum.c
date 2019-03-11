/*
** my_str_isnum.c for 42sh in /home/zahut/rendu/PSU/PSU_2016_42sh/src/builtins/utils
** 
** Made by Thibault Hebert
** Login   <thibault.hebert@epitech.eu>
** 
** Started on  Tue May  2 15:25:37 2017 Thibault Hebert
** Last update Mon May 15 15:48:59 2017 Pierre J. Alderman
*/

#include "builtins.h"

int	my_str_isnum(char *str)
{
  int	it;

  it = 0;
  while (str[it] != '\0')
    {
      if (str[it] < '0' || str[it] > '9')
	return (ERROR);
      it++;
    }
  return (SUCESS);
}
