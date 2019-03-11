/*
** del_char.c for 42sh in /home/Matthy/PSU_2016_42sh/src/utils
** 
** Made by Matthias Gayaud
** Login   <Matthy@epitech.net>
** 
** Started on  Wed May  3 14:47:24 2017 Matthias Gayaud
** Last update Sun May 21 19:28:49 2017 Matthias Gayaud
*/

#include "utils.h"

char	*del_char(char *str, int i)
{
  while (str[i] != '\0')
    {
      str[i] = str[i + 1];
      i++;
    }
  str[i] = '\0';
  return (str);
}
