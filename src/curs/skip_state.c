/*
** skip_state.c for 42sh in /home/Matthy/PSU_2016_42sh/src/curs
** 
** Made by Matthias Gayaud
** Login   <Matthy@epitech.net>
** 
** Started on  Tue May 16 19:56:16 2017 Matthias Gayaud
** Last update Tue May 16 19:56:27 2017 Matthias Gayaud
*/

#include "input.h"

char	*skip_state(t_machine_params *params, void *states)
{
  return (input_switcher(params, states));
}
