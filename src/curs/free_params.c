/*
** free_params.c for 42sh in /home/Matthy/PSU_2016_42sh/src/curs
** 
** Made by Matthias Gayaud
** Login   <Matthy@epitech.net>
** 
** Started on  Wed May  3 16:47:03 2017 Matthias Gayaud
** Last update Sun May 21 16:37:30 2017 Matthias Gayaud
*/

#include "input.h"

int	free_params(t_machine_params *params)
{
  if (tcgetattr(0, &params->terminal) == -1)
    return (-1);
  params->terminal.c_lflag = (ICANON | ECHO);
  if (tcsetattr(0, 0, &params->terminal) == -1)
    return (-1);
  free(params->curs);
  free(params->cur_str);
  free(params);
  return (0);
}
