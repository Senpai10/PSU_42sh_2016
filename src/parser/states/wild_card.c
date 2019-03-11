/*
** wild_card.c for 42sh in /home/pierre/PSU/PSU_2016_42sh/src/parser/states
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Thu Apr 27 16:38:32 2017 Pierre J. Alderman
** Last update Thu May 18 19:32:36 2017 Pierre J. Alderman
*/

#include "parser.h"

t_command	*state_wild_card(char *str, t_command *commands,
				 void *states, t_env *envp)
{
  return (p_add_token(str, commands, states, envp));
}
