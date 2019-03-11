/*
** catch_litteral_str.c for 42sh in /home/pierre/PSU/PSU_2016_42sh/src/parser
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Wed Apr 26 19:50:05 2017 Pierre J. Alderman
** Last update Thu May 18 19:33:29 2017 Pierre J. Alderman
*/

#include "parser.h"

t_command	*state_catch_litteral_str(char *str, t_command *commands,
					  void *states, t_env *envp)
{
  ++str;
  while (*str != 0 && *str != '\'')
    {
      commands->args_it->arg = su_cat(commands->args_it->arg, *str);
      ++str;
    }
  if (*str == 0)
    return (NULL);
  return (p_tokenizer(str + 1, commands, states, envp));
}
