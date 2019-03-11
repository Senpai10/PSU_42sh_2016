/*
** burn_arg.c for 42sh in /home/pierre/PSU/PSU_2016_42sh/src/parser
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Wed Apr 26 19:55:17 2017 Pierre J. Alderman
** Last update Thu May  4 11:42:26 2017 Pierre J. Alderman
*/

#include "parser.h"

void	burn_arg(t_command *commands)
{
  commands->args_it->prev->next = NULL;
  do_free((void **)&commands->args_it);
}
