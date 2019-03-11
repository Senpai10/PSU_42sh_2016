/*
** redirect_l.c for redirect_l in /home/sookaz/PSU_2016_42sh/src/execution
** 
** Made by Leo Maignan
** Login   <sookaz@epitech.net>
** 
** Started on  Tue May  9 18:28:15 2017 Leo Maignan
** Last update Sun May 21 23:20:09 2017 Senpai
*/

#include "ftsh.h"

int	redirect_l(char **args, t_command **commands, char **envp)
{
  char	*redirect;
  int	signal;
  int	fd;
  int	newfd;

  signal = 0;
  redirect = (*commands)->next->args->arg;
  if ((newfd = dup(0)) == -1)
    return (EXEC_ERROR);
  if ((fd = open(redirect, O_RDONLY)) == -1)
    perror(redirect);
  if ((dup2(fd, 0)) == -1)
    return (EXEC_ERROR);
  if ((signal = fork_exec(args, envp)) == EXEC_ERROR)
    return (EXEC_ERROR);
  if ((close(fd)) == -1)
    return (EXEC_ERROR);
  if ((dup2(newfd, 0)) == -1)
    return (EXEC_ERROR);
  if ((close(newfd)) == -1)
    return (EXEC_ERROR);
  *commands = consume_command(*commands, 2);
  return (signal);
}
