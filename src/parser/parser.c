/*
** parser.c for 42sh in /home/pierre/PSU/PSU_2016_42sh/src/parser
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Wed Apr 26 19:36:04 2017 Pierre J. Alderman
** Last update Sun May 21 22:24:12 2017 Pierre J. Alderman
*/

#include "parser.h"

static t_state		*get_states2(t_state *states)
{
  states[7].id = '*';
  states[7].function = state_wild_card;
  states[8].id = ';';
  states[8].function = state_semicolon;
  states[9].id = '>';
  states[9].function = p_r_redir;
  states[10].id = '<';
  states[10].function = p_l_redir;
  states[11].id = '\t';
  states[11].function = state_add_arg;
  states[12].id = '\n';
  states[12].function = p_ignore;
  return (states);
}

static t_state		*get_states()
{
  t_state		*states;

  states = do_malloc(sizeof(*states) * (13));
  if (states == NULL)
    return (NULL);
  states[0].id = ' ';
  states[0].function = state_add_arg;
  states[1].id = '~';
  states[1].function = state_add_home;
  states[2].id = '"';
  states[2].function = state_catch_str;
  states[3].id = '\'';
  states[3].function = state_catch_litteral_str;
  states[4].id = '(';
  states[4].function = state_catch_parenthesis;
  states[5].id = '|';
  states[5].function = p_pipe_or_or;
  states[6].id = '&';
  states[6].function = p_job_or_and;
  return (get_states2(states));
}

t_command	*parser(char *to_digest, t_env *envp)
{
  t_state	*states;
  t_command	*commands;

  states = get_states();
  if (states == NULL)
    return (NULL);
  commands = init_t_command();
  if (states == NULL)
    return (NULL);
  commands = p_tokenizer(to_digest, commands, states, envp);
  if (commands == NULL)
    return (NULL);
  do_free((void **)&states);
  while (commands->prev != NULL)
    commands = commands->prev;
  return (commands);
}
