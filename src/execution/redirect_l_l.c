/*
** redirect_l_l.c for 42sh in /home/senpai/EPITECH/PSU_2016/PSU_2016_42sh/src/execution
** 
** Made by Senpai
** Login   <charly.dai@epitech.eu>
** 
** Started on  Fri May 19 21:44:09 2017 Senpai
** Last update Sun May 21 23:22:00 2017 Senpai
*/

#include "ftsh.h"

char	*concatenation(char *line, char *redirect, char *result)
{
  while (my_strcmp(line, redirect) != 0)
    {
      write(1, "? ", 2);
      if ((line = get_next_line(0)) == NULL)
	break;
      if ((my_strcmp(line, redirect)) != 0)
	{
	  result = my_strcat(result, line);
	  result = my_strcat(result, "\n");
	}
    }
  return (result);
}

int	change_io_l_l(char **args, char **envp, int pipefd[2], int newfd)
{
  int	signal;

  if ((dup2(pipefd[0], 0)) == -1)
    return (EXEC_ERROR);
  if ((signal = fork_exec(args, envp)) == EXEC_ERROR)
    return (EXEC_ERROR);
  if ((close(pipefd[0])) == -1)
    return (EXEC_ERROR);
  if ((dup2(newfd, 0)) == -1)
    return (EXEC_ERROR);
  if ((close(newfd)) == -1)
    return (EXEC_ERROR);
  return (signal);
}

int     redirect_l_l(char **args, t_command **command, char **envp)
{
  char  *line;
  char  *result;
  char  *redirect;
  int   pipefd[2];
  int   newfd;
  int	signal;

  redirect = (*command)->next->args->arg;
  line = "\0";
  result = "\0";
  if ((newfd = dup(0)) == -1)
    return (EXEC_ERROR);
  if ((pipe(pipefd)) == -1)
    return (EXEC_ERROR);
  result = concatenation(line, redirect, result);
  if ((write(pipefd[1], result, strlen(result))) == -1)
    return (EXEC_ERROR);
  if ((close(pipefd[1])) == -1)
    return (EXEC_ERROR);
  if ((signal = change_io_l_l(args, envp, pipefd, newfd)) == EXEC_ERROR)
    return (EXEC_ERROR);
  *command = consume_command(*command, 2);
  return (signal);
}
