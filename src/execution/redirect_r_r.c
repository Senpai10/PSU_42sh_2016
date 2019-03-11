/*
** redirec_r_r.c for 42sh in /home/senpai/EPITECH/PSU_2016/PSU_2016_42sh
** 
** Made by Senpai
** Login   <charly.dai@epitech.eu>
** 
** Started on  Thu May 11 17:21:16 2017 Senpai
** Last update Sun May 21 23:23:48 2017 Senpai
*/

#include "execution.h"

int     redirect_r_r(char **args, t_command **commands, char **envp)
{
  int	fd;
  int	newfd;
  int	signal;
  char	*redirect;

  signal = 0;
  redirect = (*commands)->next->args->arg;
  if ((newfd = dup(1)) == -1)
    return (EXEC_ERROR);
  if ((fd = open(redirect, O_APPEND | O_CREAT | O_WRONLY, 0666)) == -1)
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
