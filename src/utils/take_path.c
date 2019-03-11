/*
** take_path.c for 42sh in /home/zahut/rendu/PSU/PSU_2016_42sh/src/utils
** 
** Made by Thibault Hebert
** Login   <thibault.hebert@epitech.eu>
** 
** Started on  Sun May 14 16:33:27 2017 Thibault Hebert
** Last update Wed May 17 09:59:52 2017 Pierre J. Alderman
*/

#include "utils.h"
#include "builtins.h"
#include "my.h"

char	*take_line_in_env(char **env, char *name)
{
  char	*line;
  int	it;

  it = 0;
  line = NULL;
  while (env[it] != NULL)
    {
      if (strncmp(env[it], name, strlen(name)) == SUCESS)
	{
	  if ((line = strdup(env[it])) == NULL)
	    return (NULL);
	  line += 5;
	  return (line);
	}
      it++;
    }
  return (NULL);
}

char	**take_path(char **env)
{
  char	*line;
  char	**p;

  if ((line = take_line_in_env(env, "PATH")) == NULL)
    return (NULL);
  if ((p = my_str_to_wordtab(line, ':')) == NULL)
    return (NULL);
  return (p);
}
