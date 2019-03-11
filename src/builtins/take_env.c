/*
** take_env.c for 42sh in /home/zahut/rendu/PSU/PSU_2016_42sh/src/builtins
** 
** Made by Thibault Hebert
** Login   <thibault.hebert@epitech.eu>
** 
** Started on  Mon May  1 22:22:57 2017 Thibault Hebert
** Last update Mon May 15 15:24:58 2017 Pierre J. Alderman
*/

#include "builtins.h"

void		modif_list(t_evar *env)
{
  t_evar	*tmp;

  tmp = env;
  env->prev = NULL;
  while (tmp->next != NULL)
    {
      tmp->next->prev = tmp;
      tmp = tmp->next;
    }
  env->prev = NULL;
}

char    *take_info(char *line, int status)
{
  int   it;
  char  *name;
  char  *data;

  it = 0;
  while (line[it] != '=')
    it++;
  if ((name = strndup(line, it)) == NULL)
    return (NULL);
  if (status == 1)
    return (name);
  line += it + 1;
  it = 0;
  while (line[it] != '\0')
    it++;
  if ((data = strndup(line, it)) == NULL)
    return (NULL);
  return (data);
}

int		put_in_list(t_evar **env, char *line)
{
  t_evar	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (EXEC_ERROR);
  elem->name = take_info(line, 1);
  elem->data = take_info(line, 0);
  if (elem->data == NULL || elem->name == NULL)
    {
      fprintf(stderr, "%s\n", strerror(errno));
      return (EXEC_ERROR);
    }
  elem->next = *env;
  *env = elem;
  return (SUCESS);
}

t_evar		*take_env(char **env)
{
  t_evar	*my_env;
  int		it;

  it = 0;
  my_env = NULL;
  if (env[0] == NULL)
    {
      if ((my_env = create_env()) == NULL)
	return (NULL);
      return (my_env);
    }
  while (env[it] != NULL)
    it++;
  it--;
  while (it >= 0)
    {
      if (put_in_list(&my_env, env[it]) == EXEC_ERROR)
	return (NULL);
      it--;
    }
  modif_list(my_env);
  return (my_env);
}
