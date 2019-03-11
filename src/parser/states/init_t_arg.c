/*
** init_t_arg.c for 42sh in /home/pierre/PSU/PSU_2016_42sh/src/parser
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Wed Apr 26 19:44:52 2017 Pierre J. Alderman
** Last update Thu May  4 11:45:31 2017 Pierre J. Alderman
*/

#include "parser.h"

t_arg		*init_t_arg()
{
  t_arg		*f_arg;

  f_arg = malloc(sizeof(*f_arg));
  if (!f_arg)
    return (NULL);
  f_arg->arg = NULL;
  f_arg->prev = NULL;
  f_arg->next = NULL;
  return (f_arg);
}
