/*
** exec_pipe.c for 42sh in /home/zahut/rendu/PSU/PSU_2016_42sh/src/execution
** 
** Made by Thibault Hebert
** Login   <thibault.hebert@epitech.eu>
** 
** Started on  Thu May 11 17:58:42 2017 Thibault Hebert
** Last update Sun May 21 22:52:53 2017 Leo Maignan
*/

#include "ftsh.h"

int	check_parent(int pip[2], int fd, char ***command)
{
  dup2(fd, 0);
  if (*(command + 1) != NULL)
    dup2(pip[1], 1);
  close(pip[0]);
  if (execvp((*command)[0], *command) == -1)
    return (EXEC_ERROR);
  return (SUCESS);
}

int	exec_pipe(char ***command)
{
  int   pip[2];
  pid_t pid;
  int   fd;
  int	signal;

  signal = 0;
  fd = 0;
  while (*command != NULL)
    {
      pipe(pip);
      if ((pid = fork()) == -1)
	return (EXEC_ERROR);
      else if (pid == 0 && check_parent(pip, fd, command) == -1)
	return (EXEC_ERROR);
      else
	{
	  wait(&signal);
	  close(pip[1]);
	  fd = pip[0];
	  command++;
	}
    }
  return (signal);
}
