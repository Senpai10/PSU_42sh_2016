/*
** mv_curs_r.c for 42sh in /home/pierre/PSU/PSU_2016_42sh/src/curs
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Wed May  3 14:37:59 2017 Pierre J. Alderman
** Last update Tue May 30 20:50:36 2017 Matthias Gayaud
*/

#include "input.h"

char	*mv_curs_r(t_machine_params *params, void *states)
{
  if (params->cur_str[params->curs->x] != '\0')
    {
      mv_curs(RIGHT, 1, params);
      params->curs->x++;
    }
  return (input_switcher(params, states));
}
