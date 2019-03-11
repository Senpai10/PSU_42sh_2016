/*
** my_strlen.c for 42sh in /home/zahut/rendu/PSU/PSU_2016_42sh/src/utils
** 
** Made by Thibault Hebert
** Login   <thibault.hebert@epitech.eu>
** 
** Started on  Wed May  3 14:57:03 2017 Thibault Hebert
** Last update Tue May 30 18:08:46 2017 Matthias Gayaud
*/

#include "source.h"

int	my_strlen(char *str)
{
  int	it;

  it = 0;
  while (str[it] != '\0')
    it++;
  return (it);
}
