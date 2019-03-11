/*
** insert_char.c for 42sh in /home/Matthy/PSU_2016_42sh/src/utils
** 
** Made by Matthias Gayaud
** Login   <Matthy@epitech.net>
** 
** Started on  Tue May  2 21:42:47 2017 Matthias Gayaud
** Last update Sun May 21 17:16:25 2017 Matthias Gayaud
*/

#include "utils.h"

char	*insert_char(char *str, char c, int i)
{
  char	*tmp_str;

  if ((tmp_str = strdup(str)) == NULL)
    return (NULL);
  str[i] = c;
  while (tmp_str[i] != '\0')
    {
      str[i + 1] = tmp_str[i];
      i++;
    }
  str[i + 1] = '\0';
  free(tmp_str);
  return (str);
}
