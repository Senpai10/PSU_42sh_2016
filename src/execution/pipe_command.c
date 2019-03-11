/*
** pipe_command.c for 42sh in /home/zahut/rendu/PSU/PSU_2016_42sh/src/execution
** 
** Made by Thibault Hebert
** Login   <thibault.hebert@epitech.eu>
** 
** Started on  Sat May 13 16:31:44 2017 Thibault Hebert
** Last update Sun May 21 21:25:52 2017 Pierre J. Alderman
*/

#include "ftsh.h"

int	check_command(char *command, char **envp)
{
  char	**path;
  char	*path_check;
  int	it;
  int	check;

  check = 0;
  it = 0;
  if ((path = take_path(envp)) == NULL)
    return (EXEC_ERROR);
  while (path[it] != NULL)
    {
      path_check = my_strcat(path[it], "/");
      path_check = my_strcat(path_check, command);
      if (access(path_check, X_OK) == SUCESS)
	check = 1;
      it++;
    }
  if (check == 0)
    return (ERROR);
  else
    return (SUCESS);
}

int	check_error(char ***command, char **envp)
{
  int	x;

  x = 0;
  while (command[x] != NULL)
    {
      if (check_command(command[x][0], envp) == ERROR)
	{
	  fprintf(stderr, "%s: %s\n", command[x][0], strerror(errno));
	  return (ERROR);
	}
      x++;
    }
  return (SUCESS);
}

int	pipe_command(char **args, t_command **command, char **envp)
{
  char	***cmd;
  int	signal;
  int	nb_pipe;

  signal = 0;
  (void)args;
  if ((cmd = take_pipe_command(*command)) == NULL)
    return (EXEC_ERROR);
  if (check_error(cmd, envp) == ERROR)
    return (-1);
  signal = exec_pipe(cmd);
  nb_pipe = count_pipe(*command);
  *command = consume_command(*command, nb_pipe);
  return (signal);
}
