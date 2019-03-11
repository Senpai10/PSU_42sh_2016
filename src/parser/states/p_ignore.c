/*
** p_ignore.c for 42sh in /home/pierre/PSU/PSU_2016_42sh/src
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Wed May 17 10:22:11 2017 Pierre J. Alderman
** Last update Thu May 18 17:24:00 2017 Pierre J. Alderman
*/

#include "parser.h"

t_command	*p_ignore(char *str, t_command *commands,
			  void *states, t_env *env)
{
  return (p_tokenizer(str + 1, commands, states, env));
}
