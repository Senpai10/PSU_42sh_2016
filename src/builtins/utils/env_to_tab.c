/*
** utils.c for minishell2 in /home/zahut/rendu/PSU/PSU_2016_minishell2/src
** 
** Made by Thibault Hebert
** Login   <thibault.hebert@epitech.eu>
** 
** Started on  Thu Mar 23 18:35:41 2017 Thibault Hebert
** Last update Mon May 15 15:46:41 2017 Pierre J. Alderman
*/

#include "builtins.h"

int		list_len(t_evar *env)
{
  t_evar	*elem;
  int		it;

  it = 0;
  elem = env;
  while (elem != NULL)
    {
      elem = elem->next;
      it++;
    }
  return (it);
}

char	*get_line(char *name, char *data)
{
  char	*line;

  if ((line = malloc(sizeof(char) * (strlen(name)
				     + strlen(data) + 2))) == NULL)
    return (NULL);
  if ((line = my_strcat(name, strdup("="))) == NULL)
    return (NULL);
  if ((line = my_strcat(line, data)) == NULL)
    return (NULL);
  return (line);
}

char		**env_to_tab(t_evar *env)
{
  char		**new_env;
  t_evar	*elem;
  int		it;

  elem = env;
  if ((new_env = malloc(sizeof(char *) * (list_len(env) + 1))) ==  NULL)
    return (NULL);
  it = 0;
  while (elem != NULL)
    {
      if ((new_env[it] = get_line(elem->name, elem->data)) == NULL)
	return (NULL);
      elem = elem->next;
      it++;
    }
  new_env[it] = NULL;
  return (new_env);
}
