/*
** auto_complete.c for 42sh in /home/Matthy/PSU_2016_42sh/src/curs
** 
** Made by Matthias Gayaud
** Login   <Matthy@epitech.net>
** 
** Started on  Wed May  3 16:57:28 2017 Matthias Gayaud
** Last update Tue May 16 22:27:08 2017 Matthias Gayaud
*/

#include "input.h"

char	*auto_complete(t_machine_params *params, void *states)
{
  return (input_switcher(params, states));
}
