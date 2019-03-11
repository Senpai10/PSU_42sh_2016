/*
** del_token.c for 42sh in /home/Matthy/PSU_2016_42sh/src/curs
** 
** Made by Matthias Gayaud
** Login   <Matthy@epitech.net>
** 
** Started on  Wed May  3 14:41:07 2017 Matthias Gayaud
** Last update Tue May 30 21:38:41 2017 Matthias Gayaud
*/

#include "input.h"

char	*del_token(t_machine_params *params, void *states)
{
  if (params->curs->x > 0)
    {
      if (params->curs->x + 8 <= params->w.ws_col)
	{
	  params->curs->x--;
	  params->curs->x_bound--;
	  mv_curs(LEFT, 1, params);
	  my_putchar(' ');
	  mv_curs(LEFT, 1, params);
	  del_char(params->cur_str, (params->curs->x));
	  params->cur_str[params->curs->x_bound] = ' ';
	  my_putstr(params->cur_str + params->curs->x);
	  mv_curs(LEFT, my_strlen(params->cur_str + params->curs->x), params);
	  params->cur_str[params->curs->x_bound] = '\0';
	}
    }
  return (input_switcher(params, states));
}
