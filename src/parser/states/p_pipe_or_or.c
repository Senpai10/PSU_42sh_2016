/*
** p_pipe_or_or.c for 42sh in /home/pierre/PSU/PSU_2016_42sh/src/parser
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Thu May  4 16:06:37 2017 Pierre J. Alderman
** Last update Sat May 20 17:48:53 2017 Pierre J. Alderman
*/

#include "parser.h"

t_command	*p_pipe_or_or(char *str, t_command *commands,
			      void *states, t_env *envp)
{
  int	exe;

  exe = P_DOUBLE_TOKEN(str);
  if (exe == 1)
    commands = state_add_command(commands, STATE_PIPE);
  else if (exe == 2)
    commands = state_add_command(commands, STATE_OR);
  return (p_tokenizer(str + exe, commands, states, envp));
}
