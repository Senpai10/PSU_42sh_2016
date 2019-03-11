/*
** alias.c for 42sh in /home/pierre/PSU/PSU_2016_42sh/src/builtins
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Mon May 15 11:00:33 2017 Pierre J. Alderman
** Last update Mon May 22 00:08:38 2017 Thibault Hebert
*/

#include "builtins.h"

static int		add_alias(t_alias **alias, char **args, t_env *env)
{
  t_alias	*elem;

  if ((elem = malloc(sizeof(*elem) * 1)) == NULL)
    return (BUILTINS_ERROR);
  elem->alias = args[0];
  elem->command = args[1];
  if ((elem->p_command = parser(elem->command, env)) == NULL)
    return (BUILTINS_ERROR);
  elem->prev = NULL;
  elem->next = *alias;
  if (*alias)
    (*alias)->prev = elem;
  *alias = elem;
  return (0);
}

static int	print_alias(t_alias *alias, char **args)
{
  if (alias == NULL)
    return (0);
  if (*args == NULL)
    {
      while (alias != NULL)
	{
	  printf("alias %s='%s'\n", alias->alias, alias->command);
	  alias = alias->next;
	}
    }
  else
    {
      while (alias != NULL && strcmp(alias->alias, *args) != 0)
	alias = alias->next;
      if (alias == NULL)
	printf("bash: alias: %s: not found\n", *args);
      else
	printf("alias %s='%s'\n", alias->alias, alias->command);
      return (alias == NULL ? 1 : 0);
    }
  return (0);
}

int	alias(t_env *env, char **args)
{
  char	**kv;

  if ((kv = get_kv(args[1])) == NULL)
    return (print_alias(env->alias, args + 1));
  return (add_alias(&env->alias, kv, env));
}
