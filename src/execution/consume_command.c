/*
** consume_command.c for 42sh in /home/pierre/PSU/PSU_2016_42sh
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Thu May 11 17:42:52 2017 Pierre J. Alderman
** Last update Sun May 21 20:37:49 2017 Pierre J. Alderman
*/

#include "utils.h"

t_command	*consume_command(t_command *commands,
				 unsigned int step)
{
  t_command	*tmp;

  while (commands != NULL && step != 0)
    {
      tmp = commands;
      commands = commands->next;
      if (tmp != NULL)
	burn_commands(tmp);
      --step;
    }
  return (commands);
}
