/*
** try_exit.c for 42sh in /home/pierre/PSU/PSU_2016_42sh/src/curs
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Wed May  3 14:19:00 2017 Pierre J. Alderman
** Last update Tue May 30 20:03:46 2017 Matthias Gayaud
*/

#include "input.h"

char	*try_exit(t_machine_params *params, void *states)
{
  if (params->cur_str[0] == '\0')
    {
      /* my_putstr("exit\n"); */
      /* return (params->cur_str); */
      return (NULL);
    }
  return (input_switcher(params, states));
}
