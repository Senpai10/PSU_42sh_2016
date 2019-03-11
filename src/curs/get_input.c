/*
** get_input.c for 42sh in /home/Matthy/PSU_2016_42sh/src/curs
** 
** Made by Matthias Gayaud
** Login   <Matthy@epitech.net>
** 
** Started on  Thu May  4 17:15:51 2017 Matthias Gayaud
** Last update Wed May 31 09:23:04 2017 Matthias Gayaud
*/

#include "input.h"

void	add_state(ISD *states, int id, t_input_state func)
{
  states[id].id = id;
  states[id].func = func;
}

static ISD	*get_states()
{
  ISD		*states;

  if ((states = malloc(sizeof(*states) * (INPUT_NB_STATES + 1))) == NULL)
    return (NULL);
  add_state(states, FTSH_SKIP_STATE, skip_state);
  add_state(states, FTSH_BASIC_CHAR, add_token);
  add_state(states, FTSH_TAB, auto_complete);
  add_state(states, FTSH_BACKSPACE, del_token);
  add_state(states, FTSH_CTRL_D, try_exit);
  add_state(states, FTSH_KEY_RIGHT, mv_curs_r);
  add_state(states, FTSH_KEY_LEFT, mv_curs_l);
  add_state(states, FTSH_KEY_UP, prev_str);
  add_state(states, FTSH_KEY_DOWN, next_str);
  return (states);
}

char			*get_input(int fd)
{
  char			*line;
  ISD			*states;
  t_machine_params	*params;

  if (isatty(fd) == 0)
    {
      if ((line = get_next_line(fd)) == NULL)
	return (NULL);
      return (line);
    }
  if ((states = get_states()) == NULL)
    return (NULL);
  if ((params = init_machine_params()) == NULL)
    return (NULL);
  if ((line = input_switcher(params, states)) == NULL)
    {
      free(states);
      if (free_params(params) == -1)
	return (NULL);
      return (NULL);
    }
  free(states);
  if (free_params(params) == -1)
    return (NULL);
  return (line);
}
