/*
** burn_commands.c for 42sh in /home/pierre/PSU/PSU_2016_42sh/src/parser
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Wed Apr 26 19:52:39 2017 Pierre J. Alderman
** Last update Sun May 21 20:44:34 2017 Pierre J. Alderman
*/

#include "utils.h"

void		burn_commands(t_command *commands)
{
  t_arg		*args;
  t_arg		*args_tmp;

  args = commands->args;
  while (args != NULL)
    {
      args_tmp = args;
      args = args->next;
      free(args_tmp->arg);
      free(args_tmp);
    }
  free(commands);
}
