/*
** su_cat.c for 42sh in /home/pierre/PSU/PSU_2016_42sh/src/parser
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Wed Apr 26 19:54:40 2017 Pierre J. Alderman
** Last update Mon May 22 00:20:31 2017 Thibault Hebert
*/

#include "source.h"

char	*su_cat(char *s, char c)
{
  int	s_len;

  s_len = (s != NULL ? strlen(s) : 0);
  s = realloc(s, sizeof(*s) * (s_len + 2));
  memcpy(&s[s_len], &c, 1);
  s[s_len + 1] =  0;
  return (s);
}
