/*
** return_str.c for 42sh in /home/Matthy/PSU_2016_42sh/src/curs
** 
** Made by Matthias Gayaud
** Login   <Matthy@epitech.net>
** 
** Started on  Wed May  3 16:43:00 2017 Matthias Gayaud
** Last update Tue May 30 20:00:12 2017 Matthias Gayaud
*/

#include "input.h"

char	*return_str(t_machine_params *params)
{
  char	*line;

  if ((line = strdup(params->cur_str)) == NULL)
    return (NULL);
  my_putchar('\n');
  return (line);
}
