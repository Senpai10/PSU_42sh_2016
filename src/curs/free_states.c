/*
** free_states.c for 42sh in /home/Matthy/PSU_2016_42sh/src/curs
** 
** Made by Matthias Gayaud
** Login   <Matthy@epitech.net>
** 
** Started on  Thu May  4 18:02:31 2017 Matthias Gayaud
** Last update Sat May 20 14:05:21 2017 Matthias Gayaud
*/

#include "input.h"

void	free_states(ISD *states)
{
  do_free((void**)states->func);
  do_free((void**)states);
}
