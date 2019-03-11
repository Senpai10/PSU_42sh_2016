/*
** p_l_redir.c for 42sh in /home/pierre/PSU/PSU_2016_42sh/src/parser/states
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Tue May  9 15:05:04 2017 Pierre J. Alderman
** Last update Sun May 21 22:27:58 2017 Pierre J. Alderman
*/

#include "parser.h"

t_command	*p_l_redir(char *str, t_command *commands,
			   void *states, t_env *envp)
{
  int	exe;

  if (commands->args->arg == NULL ||
      (commands->prev && (commands->prev->state == STATE_L_REDIR ||
			  commands->prev->state == STATE_DL_REDIR)))
    return (p_unexpected_token(*str));
  exe = P_DOUBLE_TOKEN(str);
  commands = state_add_command(commands, (exe == 1 ?
					  STATE_L_REDIR : STATE_DL_REDIR));
  return (p_tokenizer(str + exe, commands, states, envp));
}
