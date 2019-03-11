/*
** p_add_token.c for 42sh in /home/pierre/PSU/PSU_2016_42sh/src/parser
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Thu May  4 12:43:56 2017 Pierre J. Alderman
** Last update Sat May 20 16:51:01 2017 Pierre J. Alderman
*/

#include "parser.h"

t_command	*p_add_token(char *str, t_command *commands,
			     void *states, t_env *env)
{
  commands->args_it->arg = su_cat(commands->args_it->arg, *str);
  return (p_tokenizer(str + 1, commands, states, env));
}
