/*
** p_append_command.c for 42sh in /home/pierre/PSU/PSU_2016_42sh/src/parser/states
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Tue May 16 16:25:33 2017 Pierre J. Alderman
** Last update Sat May 20 16:47:51 2017 Pierre J. Alderman
*/

#include "parser.h"

t_command	*p_append_command(t_command *elem,
				  t_command *commands)
{
  if (commands == NULL || commands->prev == NULL)
    return (elem);
  commands->next = elem;
  elem->prev = commands;
  return (elem);
}

static t_command	*roll_back_args(t_command *p)
{
  while (p->args->prev != NULL)
    p->args = p->args->next;
  return (p);
}

t_command	*p_dup_command(t_command *c_p)
{
  t_command	*d;
  t_arg		*t;
  t_arg		*p;

  p = c_p->args;
  if ((d = memdup(c_p, sizeof(*c_p))) == NULL)
    return (NULL);
  d->args = memdup(p, sizeof(*(p)));
  t = NULL;
  while (p != NULL)
    {
      d->args->arg = strdup(p->arg);
      d->args->prev = t;
      if (t != NULL)
	t->next = d->args;
      t = d->args;
      p = p->next;
    }
  t->next = NULL;
  d->args_it = memdup(d->args, sizeof(*(d->args)));
  d->nb_args = c_p->nb_args;
  d->state = c_p->state;
  d->next = c_p->next;
  d->prev = c_p->prev;
  return (roll_back_args(d));
}
