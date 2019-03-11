/*
** utils.c for minishell2 in /home/zahut/rendu/PSU/PSU_2016_minishell2/src
** 
** Made by Thibault Hebert
** Login   <thibault.hebert@epitech.eu>
** 
** Started on  Thu Mar 23 18:35:41 2017 Thibault Hebert
** Last update Mon May 22 00:20:11 2017 Thibault Hebert
*/

#include "source.h"

int	list_len(t_env *env)
{
  t_env	*elem;
  int	it;

  it = 0;
  elem = env;
  while (elem->next != env)
    {
      elem = elem->next;
      it++;
    }
  return (it);
}

char	*get_line(char *name, char *data)
{
  char	*line;

  if ((line = malloc(sizeof(char) * (my_strlen(name)
				     + my_strlen(data) + 2))) == NULL)
    exit(84);
  line = my_strcat(name, my_strdup("="));
  line = my_strcat(line, data);
  return (line);
}

char	**env_to_tab(t_env *env)
{
  char	**new_env;
  t_env	*elem;
  int	it;

  elem = env;
  if ((new_env = malloc(sizeof(char *) * (list_len(env) + 1))) ==  NULL)
    exit(84);
  it = 0;
  while (elem->next != env)
    {
      new_env[it] = get_line(elem->name, elem->data);
      elem = elem->next;
      it++;
    }
  new_env[it - 1] = get_line(elem->name, elem->data);
  new_env[it] = NULL;
  return (new_env);
}
