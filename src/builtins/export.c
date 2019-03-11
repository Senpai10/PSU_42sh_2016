/*
** export.c for 42sh in /home/pierre/PSU/PSU_2016_42sh/src/builtins
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Sun May 14 18:43:26 2017 Pierre J. Alderman
** Last update Sun May 21 21:03:08 2017 Pierre J. Alderman
*/

#include "builtins.h"

char	**get_kv(char *str)
{
  int	i;
  char	**command;

  if (str == NULL)
    return (NULL);
  i = 0;
  while (str[i] != '\0' && str[i] != '=')
    ++i;
  if (str[i] == '\0')
    return (NULL);
  command = malloc(sizeof(*command) * 4);
  command[0] = strdup("");
  command[1] = strndup(str, i);
  command[2] = strdup(str + i + 1);
  command[3] = NULL;
  return (command);
}

int	export(t_env *env, char **args)
{
  char	**command;

  if ((command = get_kv(args[1])) == NULL)
    return (0);
  return (my_setenv(env, command));
}
