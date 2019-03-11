/*
** get_pressed_key.c for 42sh in /home/Matthy/PSU_2016_42sh/src/curs
** 
** Made by Matthias Gayaud
** Login   <Matthy@epitech.net>
** 
** Started on  Tue May 16 22:12:17 2017 Matthias Gayaud
** Last update Tue May 16 22:26:40 2017 Matthias Gayaud
*/

#include "input.h"

int	check_direction_key(char *str)
{
  if (str[0] == 27 && str[2] == 65)
    return (7);
  if (str[0] == 27 && str[2] == 66)
    return (8);
  if (str[0] == 27 && str[2] == 67)
    return (5);
  if (str[0] == 27 && str[2] == 68)
    return (6);
  return (0);
}

int	get_pressed_key(char *str)
{
  int	id;

  id = 0;
  id = check_direction_key(str);
  if (id != 0)
    return (id);
  if (str[0] == 4)
    return (4);
  if (str[0] == 127)
    return (3);
  if (str[0] == '\t')
    return (2);
  if (str[0] >= 32)
    return (1);
  return (0);
}
