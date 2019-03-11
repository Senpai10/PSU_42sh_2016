/*
** add_command.c for 42sh in /home/pierre/PSU/PSU_2016_42sh/src/parser
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Wed Apr 26 19:47:57 2017 Pierre J. Alderman
** Last update Thu May 18 19:33:02 2017 Pierre J. Alderman
*/

#include "parser.h"

t_command	*state_add_command(t_command *commands,
				   t_exe_state state)
{
  t_command	*tmp;

  if (commands->args->arg == NULL)
    return (commands);
  if (state == STATE_FINAL_COMMAND)
    tmp = NULL;
  else
    {
      tmp = init_t_command();
      if (tmp == NULL)
	return (NULL);
      tmp->prev = commands;
    }
  if (commands->args_it->arg == NULL)
    burn_arg(commands);
  commands->command = commands->args->arg;
  commands->args_it = commands->args;
  commands->state = state;
  commands->next = tmp;
  return (commands->next);
}
