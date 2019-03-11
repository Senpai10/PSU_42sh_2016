/*
** charlyfdp.c for strclo in /home/senpai/EPITECH/PSU_2016/PSU_2016_42sh
** 
** Made by Senpai
** Login   <charly.dai@epitech.eu>
** 
** Started on  Tue May  9 13:25:18 2017 Senpai
** Last update Mon May 22 00:20:54 2017 Thibault Hebert
*/

#include "source.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;
  int	len;
  int	len2;

  i = 0;
  len = my_strlen(s1);
  len2 = my_strlen(s2);
  if (len != len2)
    return (-1);
  while (s1[i] != '\0')
    {
      if (s1[i] != s2[i])
	return (-1);
      i = i + 1;
    }
  return (0);
}
