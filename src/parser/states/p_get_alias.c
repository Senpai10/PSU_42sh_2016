/*
** p_get_alias.c for 42sh in /home/pierre/PSU/PSU_2016_42sh/src/parser/states
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Tue May 16 16:04:14 2017 Pierre J. Alderman
** Last update Sat May 20 16:56:46 2017 Pierre J. Alderman
*/

#include "parser.h"

t_command      	*p_get_alias(char *str, t_env *env)
{
  t_alias	*it;

  it = env->alias;
  while (it !=  NULL)
    {
      if (strcmp(str, it->alias) == 0)
	return (p_dup_command(it->p_command));
      it = it->next;
    }
  return (NULL);
}
