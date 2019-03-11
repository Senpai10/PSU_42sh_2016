/*
** input_switcher.c for 42sh in /home/pierre/PSU/PSU_2016_42sh/src/parser
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Tue May  2 16:38:43 2017 Pierre J. Alderman
** Last update Tue May 30 22:02:00 2017 Matthias Gayaud
*/

#include "ftsh.h"

static t_input_state	get_state(int c, const ISD *states)
{
  int		i;

  i = 0;
  while (i < INPUT_NB_STATES + 1)
    {
      if (states[i].id == c)
	return (states[i].func);
      ++i;
    }
  return (skip_state);
}

char		       	*input_switcher(t_machine_params *params, void *states)
{
  t_input_state	       	state;
  int			tmp_col;

  tmp_col = params->w.ws_col;
  ioctl(0, TIOCGWINSZ, &params->w);
  if (tmp_col != params->w.ws_col)
    return (NULL);
  read(0, params->buffer, 3);
  if (params->buffer[0] == '\n' || params->buffer[0] == '\0')
    return (return_str(params));
  params->input = get_pressed_key(params->buffer);
  state = get_state(params->input, states);
  return (state(params, states));
}
