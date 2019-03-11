/*
** p_r_redir.c for 42sh in /home/pierre/PSU/PSU_2016_42sh/src/parser
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Thu May  4 17:23:10 2017 Pierre J. Alderman
** Last update Sun May 21 22:28:15 2017 Pierre J. Alderman
*/

#include "parser.h"

t_command	*p_r_redir(char *str, t_command *commands,
			   void *states, t_env *envp)
{
  int	exe;

  if (commands->args->arg == NULL ||
      (commands->prev && (commands->prev->state == STATE_R_REDIR ||
			  commands->prev->state == STATE_DR_REDIR)))
    return (p_unexpected_token(*str));
  exe = P_DOUBLE_TOKEN(str);
  commands = state_add_command(commands, (exe == 1
					  ? STATE_R_REDIR : STATE_DR_REDIR));
  return (p_tokenizer(str + exe, commands, states, envp));
}
