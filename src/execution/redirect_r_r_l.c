/*
** redirect_r_l.c for 42sh in /home/senpai/EPITECH/PSU_2016/PSU_2016_42sh
** 
** Made by Senpai
** Login   <charly.dai@epitech.eu>
** 
** Started on  Sun May 21 18:51:43 2017 Senpai
** Last update Mon May 22 01:27:11 2017 Thibault Hebert
*/

#include "execution.h"

int	reset_io_r_r_l(int fd_r, int fd_l, int newfd_r, int newfd_l)
{
  if ((close(fd_r)) == -1)
    return (EXEC_ERROR);
  if ((close(fd_l)) == -1)
    return (EXEC_ERROR);
  if ((dup2(newfd_r, 1)) == -1)
    return (EXEC_ERROR);
  if ((dup2(newfd_l, 0)) == -1)
    return (EXEC_ERROR);
  if ((close(newfd_r)) == -1)
    return (EXEC_ERROR);
  if ((close(newfd_l)) == -1)
    return (EXEC_ERROR);
  return (0);
}

int	change_io_r_r_l(int fd_r, int fd_l, char **args, char **envp)
{
  int	signal;

  if ((dup2(fd_l, 0)) == -1)
    return (EXEC_ERROR);
  if ((dup2(fd_r, 1)) == -1)
    return (EXEC_ERROR);
  if ((signal = fork_exec(args, envp)) == EXEC_ERROR)
    return (EXEC_ERROR);
  return (signal);
}

int     redirect_r_r_l(char **args, t_command **commands, char **envp)
{
  int   fd_l;
  int   fd_r;
  int   newfd_l;
  int   newfd_r;
  int   signal;
  char  *redir_r;
  char  *redir_l;

  redir_r = (*commands)->next->args->arg;
  redir_l = (*commands)->next->next->args->arg;
  if ((newfd_r = dup(1)) == -1)
    return (EXEC_ERROR);
  if ((newfd_l = dup(0)) == -1)
    return (EXEC_ERROR);
  if ((fd_l = open(redir_l, O_RDONLY)) == -1)
    perror(redir_l);
  else
    if ((fd_r = open(redir_r, O_APPEND | O_CREAT | O_WRONLY, 0666)) == -1)
      return (EXEC_ERROR);
  if (((signal = change_io_r_r_l(fd_r, fd_l, args, envp)) == EXEC_ERROR) ||
      (reset_io_r_r_l(fd_r, fd_l, newfd_r, newfd_l)) == EXEC_ERROR)
    return (EXEC_ERROR);
  *commands = consume_command(*commands, 3);
  return (signal);
}
