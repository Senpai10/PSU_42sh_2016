/*
** redirec_r.c for 42sh in /home/senpai/EPITECH/PSU_2016/PSU_2016_42sh/src/execution
** 
** Made by Senpai
** Login   <charly.dai@epitech.eu>
** 
** Started on  Mon May  8 11:04:35 2017 Senpai
** Last update Sun May 21 23:22:34 2017 Senpai
*/

#include "execution.h"

int	redirect_r(char **args, t_command **commands, char **envp)
{
  int	fd;
  int	newfd;
  int	signal;
  char	*redirect;

  redirect = (*commands)->next->args->arg;
  if ((newfd = dup(1)) == -1)
    return (EXEC_ERROR);
  remove(redirect);
  if ((fd = open(redirect, O_CREAT | O_WRONLY, 0666)) == -1)
    return (EXEC_ERROR);
  if ((dup2(fd, 1)) == -1)
    return (EXEC_ERROR);
  if ((signal = fork_exec(args, envp)) == EXEC_ERROR)
    return (EXEC_ERROR);
  if ((close(fd)) == -1)
    return (EXEC_ERROR);
  if ((dup2(newfd, 1)) == -1)
    return (EXEC_ERROR);
  if ((close(newfd)) == -1)
    return (EXEC_ERROR);
  *commands = consume_command(*commands, 2);
  return (signal);
}
