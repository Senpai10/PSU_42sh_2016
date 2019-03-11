/*
** browse.c for 42sh in /home/pierre/PSU/PSU_2016_42sh/src/parser
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Wed Apr 26 19:40:19 2017 Pierre J. Alderman
** Last update Sun May 21 22:27:13 2017 Pierre J. Alderman
*/

#include "parser.h"
#include "builtins.h"

static t_state_func   	get_state(char c, t_state *states)
{
  int		i;

  i = 0;
  while (i < NB_STATES + 1)
    {
      if (states[i].id == c)
	return (states[i].function);
      ++i;
    }
  return (p_add_token);
}

t_command	*p_tokenizer(char *str, t_command *commands,
			     void *states, t_env *envp)
{
  t_state_func	state;

  if (!str)
    return (NULL);
  if (*str == 0)
    return (p_end_of_digest(commands, envp));
  state = get_state(*str, states);
  return (state(str, commands, states, envp));
}
