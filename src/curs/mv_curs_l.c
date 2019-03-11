/*
** mv_curs_l.c for 42sh in /home/pierre/PSU/PSU_2016_42sh/src/curs
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Wed May  3 15:01:26 2017 Pierre J. Alderman
** Last update Tue May 30 20:50:55 2017 Matthias Gayaud
*/

#include "input.h"

char	*mv_curs_l(t_machine_params *params, void *states)
{
  if (params->curs->x > 0)
    {
      mv_curs(LEFT, 1, params);
      params->curs->x--;
    }
  return (input_switcher(params, states));
}
