/*
** my_putstr.c for 42sh in /home/zahut/rendu/PSU/PSU_2016_42sh/src/utils
** 
** Made by Thibault Hebert
** Login   <thibault.hebert@epitech.eu>
** 
** Started on  Thu May  4 16:01:59 2017 Thibault Hebert
** Last update Thu May  4 16:04:49 2017 Thibault Hebert
*/

#include "utils.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  write(1, str, strlen(str));
}
