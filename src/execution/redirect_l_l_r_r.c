/*
** redirect_r_l_l.c for 42sh in /home/senpai/EPITECH/PSU_2016/PSU_2016_42sh
** 
** Made by Senpai
** Login   <charly.dai@epitech.eu>
** 
** Started on  Sun May 21 19:20:52 2017 Senpai
** Last update Sun May 21 23:21:36 2017 Senpai
*/

#include "execution.h"

int	reset_io_l_l_r_r(int fd_r, int pipefd[2], int newfd_r, int newfd_l_l)
{
  if ((close(fd_r)) == -1)
    return (EXEC_ERROR);
  if ((close(pipefd[0])) == -1)
    return (EXEC_ERROR);
  if ((dup2(newfd_r, 1)) == -1)
    return (EXEC_ERROR);
  if ((dup2(newfd_l_l, 0)) == -1)
    return (EXEC_ERROR);
  if ((close(newfd_r)) == -1)
    return (EXEC_ERROR);
  if ((close(newfd_l_l)) == -1)
    return (EXEC_ERROR);
  return (0);
}

int	change_io_l_l_r_r(int fd_r, int pipefd[2], char **args, char **envp)
{
  int	signal;

  if ((dup2(fd_r, 1)) == -1)
    return (EXEC_ERROR);
  if ((dup2(pipefd[0], 0)) == -1)
    return (EXEC_ERROR);
  if ((signal = fork_exec(args, envp)) == EXEC_ERROR)
    return (EXEC_ERROR);
  return (signal);
}

int    concatenation_l_l_r_r(char *redir_l_l, int pipefd[2])
{
  char  *line;
  char  *result;

  line = "\0";
  result = "\0";
  while (my_strcmp(line, redir_l_l) != 0)
    {
      write(1, "? ", 2);
      if ((line = get_next_line(0)) == NULL)
        break;
      if ((my_strcmp(line, redir_l_l)) != 0)
        {
          result = my_strcat(result, line);
          result = my_strcat(result, "\n");
        }
    }
  if ((write(pipefd[1], result, strlen(result))) == -1)
    return (EXEC_ERROR);
  if ((close(pipefd[1])) == -1)
    return (EXEC_ERROR);
  return (0);
}

int     redirect_l_l_r_r(char **args, t_command **command, char **envp)
{
  char  *redir_r;
  char	*redir_l_l;
  int   pipefd[2];
  int	fd_r;
  int	newfd_r;
  int   newfd_l_l;
  int   signal;

  redir_r = (*command)->next->next->args->arg;
  redir_l_l = (*command)->next->args->arg;
  if ((newfd_r = dup(1)) == -1)
    return (EXEC_ERROR);
  if ((newfd_l_l = dup(0)) == -1)
    return (EXEC_ERROR);
  if ((fd_r = open(redir_r, O_APPEND | O_CREAT | O_WRONLY, 0666)) == -1)
    return (EXEC_ERROR);
  if ((pipe(pipefd)) == -1)
    return (EXEC_ERROR);
  if (((concatenation_l_l_r_r(redir_l_l, pipefd)) == EXEC_ERROR) ||
      ((signal = change_io_l_l_r_r(fd_r, pipefd, args, envp)) == EXEC_ERROR) ||
      (reset_io_l_l_r_r(fd_r, pipefd, newfd_r, newfd_l_l)) == EXEC_ERROR)
    return (EXEC_ERROR);
  *command = consume_command(*command, 3);
  return (signal);
}
