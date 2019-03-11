/*
** my_str_to_word_tab.c for library in /home/thibault/PSU/PSU_2016_minishell1/lib/my
** 
** Made by Thibault Hebert
** Login   <thibault@epitech.net>
** 
** Started on  Mon Jan 16 13:30:22 2017 Thibault Hebert
** Last update Wed May 17 10:01:53 2017 Pierre J. Alderman
*/

#include "source.h"

int	count_word(char *str, char c)
{
  int	i;
  int	n_word;

  i = 0;
  n_word = 0;
  while (str[i] == c && str[i] != '\0')
    i++;
  if (str[i] != '\0')
    n_word++;
  while (str[i] != '\0')
    {
      if (str[i] == c)
	{
	  while (str[i] == c)
	    i++;
	  if (str[i] != '\0')
	    n_word++;
	  else
	    return (n_word);
	}
      i++;
    }
  return (n_word);
}

int	my_strnlen(char **str, char c, int status)
{
  int	i;

  i = 0;
  if (status == 1)
    {
      while ((*str)[i] != c && (*str)[i] != '\0')
	i++;
      return (i);
    }
  if (status == 2)
    {
      while ((*str)[i] != c && (*str)[i] != '\0')
	i++;
      while ((*str)[i] == c && (*str)[i] != '\0')
	i++;
      (*str) = &(*str)[i];
    }
  return (0);
}

char	**put_int_tab(char **p, char *str, char c, int line)
{
  int	i;

  i = 0;
  while (str[i] != c && str[i] != '\0')
    {
      p[line][i] = str[i];
      i++;
    }
  p[line][i] = '\0';
  return (p);
}

char	**my_str_to_wordtab(char *str, char c)
{
  char	**p;
  int	nb;
  int	i;

  if (str == NULL)
    return (NULL);
  i = 0;
  nb = count_word(str, c);
  p = malloc(sizeof(char *) * (nb + 1));
  if (p == NULL)
    return (NULL);
  while (i < nb)
    {
      if ((p[i] = malloc(sizeof(char) * (my_strnlen(&str, c, 1) + 1))) == NULL)
	return (NULL);
      p = put_int_tab(p, str, c, i);
      my_strnlen(&str, c, 2);
      i++;
    }
  p[i] = NULL;
  return (p);
}
