/*
** semicolon.c for 42sh in /home/pierre/PSU/PSU_2016_42sh/src/parser
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Tue May  2 14:21:41 2017 Pierre J. Alderman
** Last update Sat May 20 17:39:57 2017 Pierre J. Alderman
*/

#include "parser.h"

t_command	*state_semicolon(char *str, t_command *commands,
				 void *states, t_env *envp)
{
  if (commands->args == NULL)
    return (p_unexpected_token(*str));
  commands = state_add_command(commands, STATE_REG);
  return (p_tokenizer(str + 1, commands, states, envp));
}
