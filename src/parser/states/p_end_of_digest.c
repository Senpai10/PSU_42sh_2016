/*
** p_end_of_digest.c for 42sh in /home/pierre/PSU/PSU_2016_42sh/src/parser
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Thu May  4 12:40:01 2017 Pierre J. Alderman
** Last update Sat May 20 17:12:36 2017 Pierre J. Alderman
*/

#include "parser.h"

t_command	*p_end_of_digest(t_command *commands, t_env *envp)
{
  t_command	*alias;

  if (commands == NULL || commands->args->arg == NULL)
    return (NULL);
  if (commands->args->arg != NULL)
    {
      if (commands->args_it->prev == NULL &&
      (alias = p_get_alias(commands->args_it->arg, envp)) != NULL)
    commands = p_append_command(alias, commands);
      state_add_command(commands, STATE_FINAL_COMMAND);
    }
  else
    {
      commands = commands->prev;
      commands->state = STATE_FINAL_COMMAND;
      commands->next = NULL;
    }
  return (commands);
}
