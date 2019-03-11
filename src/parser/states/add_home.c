/*
** add_home.c for 42sh in /home/pierre/PSU/PSU_2016_42sh/src/parser/states
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Thu Apr 27 16:35:15 2017 Pierre J. Alderman
** Last update Thu May 18 19:33:41 2017 Pierre J. Alderman
*/

#include "parser.h"

t_command	*state_add_home(char *str, t_command *commands,
				void *states, t_env *envp)
{
  return (p_tokenizer(str + 1, commands, states, envp));
}
