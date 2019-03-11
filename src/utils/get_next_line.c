/*
** get_next_line.c for get_next_line in /home/thibault/CPE/CPE_2017_getnextline
** 
** Made by Thibault Hebert
** Login   <thibault@epitech.net>
** 
** Started on  Fri Jan  6 13:38:46 2017 Thibault Hebert
** Last update Wed May  3 13:37:12 2017 Thibault Hebert
*/

#include "source.h"

int	test_n(char *buff, int status)
{
  int	i;

  i = -1;
  if (status == 0)
    {
      while (buff[++i] != '\0')
	{
	  if (buff[i] == '\n')
	    return (LINE);
	}
      return (NO_LINE);
    }
  else if (status == 1)
    {
      i = 0;
      while (buff[i] != '\0')
	i++;
      return (i);
    }
  return (0);
}

char	*div_set_line(char **save, char *line)
{
  int	i;

  i = 0;
  line = malloc(sizeof(char) * (strlen((*save)) + 1));
  while ((*save)[i] != '\n')
    {
      line[i] = (*save)[i];
      i++;
    }
  (*save) = &((*save)[i + 1]);
  line[i] = '\0';
  return (line);
}

char	*test(char *line, char *save)
{
  if (save[0] == '\0')
    return (NULL);
  line = save;
  save = "\0";
  return (line);
}

char		*get_next_line(const int fd)
{
  char		*line;
  char		*buff;
  int		read_back;
  static char	*save = "\0";

  line = "\0";
  buff = malloc(sizeof(char) * (READ_SIZE + 1));
  if (buff == NULL)
    return (NULL);
  buff[0] = '\0';
  while (test_n(save, 0) == NO_LINE)
    {
      if ((read_back = read(fd, buff, READ_SIZE)) == -1)
  	return (NULL);
      if (read_back == 0)
  	{
	  line = test(line, save);
  	  return (line);
  	}
      buff[read_back] = '\0';
      save = my_strcat(save, buff);
    }
  line = div_set_line(&save, line);
  free(buff);
  return (line);
}
