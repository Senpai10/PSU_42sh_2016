/*
** add_token.c for 42sh in /home/Matthy/PSU_2016_42sh/src/curs
** 
** Made by Matthias Gayaud
** Login   <Matthy@epitech.net>
** 
** Started on  Tue May  2 17:57:23 2017 Matthias Gayaud
** Last update Tue May 30 21:34:09 2017 Matthias Gayaud
*/

#include "input.h"

char	*add_token(t_machine_params *params, void *states)
{
  if (params->curs->x_bound == params->w.ws_col - 9)
    return (input_switcher(params, states));
  if ((params->cur_str = insert_char(params->cur_str, params->buffer[0],
				     params->curs->x)) == NULL)
    return (NULL);
  if (params->curs->x < params->w.ws_col)
    {
      params->curs->x++;
      params->curs->x_bound++;
    }
  my_putchar(params->buffer[0]);
  my_putstr(params->cur_str + params->curs->x);
  mv_curs(LEFT, my_strlen(params->cur_str + params->curs->x), params);
  return (input_switcher(params, states));
}
