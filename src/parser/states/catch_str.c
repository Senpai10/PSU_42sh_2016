/*
** catch_str.c for 42sh in /home/pierre/PSU/PSU_2016_42sh/src/parser/states
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Thu Apr 27 16:36:19 2017 Pierre J. Alderman
** Last update Sun May 21 21:57:54 2017 Pierre J. Alderman
*/

#include "parser.h"

t_command	*state_catch_str(char *str, t_command *commands,
				 void *states, t_env *envp)
{
  return (state_catch_litteral_str(str, commands, states, envp));
}
