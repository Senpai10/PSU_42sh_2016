/*
** take_pipe_command.c for 42sh in /home/zahut/rendu/PSU/PSU_2016_42sh/src/execution
** 
** Made by Thibault Hebert
** Login   <thibault.hebert@epitech.eu>
** 
** Started on  Fri May 12 09:42:04 2017 Thibault Hebert
** Last update Mon May 22 00:36:18 2017 Thibault Hebert
*/

#include "ftsh.h"

int		count_pipe(t_command *command)
{
  t_command	*tmp;
  int		it;

  it = 0;
  tmp = command;
  while (tmp != NULL && tmp->state == STATE_PIPE)
    {
      it++;
      tmp = tmp->next;
    }
  return (it + 1);
}

char	*get_tab_line(t_arg *tmp)
{
  char	*line;

  if ((line = malloc(sizeof(char) * (strlen(tmp->arg)))) == NULL)
    return (NULL);
  if ((line = strdup(tmp->arg)) == NULL)
    return (NULL);
  return (line);
}

char	**take_command_pipe(t_arg *arg)
{
  int	it;
  t_arg	*tmp;
  char	**p;

  it = 0;
  tmp = arg;
  while (tmp != NULL)
    {
      it++;
      tmp = tmp->next;
    }
  if ((p = malloc(sizeof(char *) * (it + 1))) == NULL)
    return (NULL);
  it = 0;
  tmp = arg;
  while (tmp != NULL)
    {
      if ((p[it] = get_tab_line(tmp)) == NULL)
	return (NULL);
      tmp = tmp->next;
      it++;
    }
  p[it] = NULL;
  return (p);
}

char		***take_pipe_command(t_command *command)
{
  int		it;
  t_command	*tmp;
  char		**command_tab;
  char		***command_pipe;

  it = 0;
  tmp = command;
  if ((command_pipe = malloc(sizeof(char **)
			     * (count_pipe(command) + 1))) == NULL)
    return (NULL);
  while (tmp->next != NULL)
    {
      if (tmp->state == STATE_PIPE)
	if ((command_tab = take_command_pipe(tmp->args)) == NULL)
	  return (NULL);
      command_pipe[it] = command_tab;
      it++;
      tmp = tmp->next;
    }
  if ((command_tab = take_command_pipe(tmp->args)) == NULL)
    return (NULL);
  command_pipe[it] = command_tab;
  command_pipe[it + 1] = NULL;
  return (command_pipe);
}
