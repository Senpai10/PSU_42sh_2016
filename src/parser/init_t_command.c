/*
** init_t_command.c for 42sh in /home/pierre/PSU/PSU_2016_42sh/src/parser
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Wed Apr 26 19:45:56 2017 Pierre J. Alderman
** Last update Sun May 21 22:25:52 2017 Pierre J. Alderman
*/

#include "parser.h"

t_command	*init_t_command()
{
  t_command	*futur_command;

  futur_command = malloc(sizeof(*futur_command));
  if (!futur_command)
    return (NULL);
  futur_command->next = NULL;
  futur_command->prev = NULL;
  futur_command->command = NULL;
  if ((futur_command->args = init_t_arg()) == NULL)
    return (NULL);
  futur_command->args_it = futur_command->args;
  futur_command->state = NO_STATE;
  futur_command->nb_args = 0;
  return (futur_command);
}
