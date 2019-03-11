/*
** my_strcat.c for day 7 in /home/thibault/CPool_Day07
** 
** Made by thibault hebert
** Login   <thibault@epitech.net>
** 
** Started on  Wed Oct 12 15:25:26 2016 thibault hebert
** Last update Wed May  3 11:43:18 2017 Senpai
*/

#include "source.h"

char	*my_strcat(char *dest, char *src)
{
  char	*result;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if (src == NULL)
    return (dest);
  if ((result = malloc(sizeof(char) * (strlen(dest)
				       + strlen(src) + 1))) == NULL)
    return (NULL);
  while (dest[i] != '\0')
    {
      result[i] = dest[i];
      i++;
    }
  while (src[j] != '\0')
    {
      result[i] = src[j];
      i++;
      j++;
    }
  result[i] = '\0';
  return (result);
}
