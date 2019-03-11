/*
** or_and.c for or and in /home/sookaz/PSU_2016_42sh/src/execution
** 
** Made by Leo Maignan
** Login   <sookaz@epitech.net>
** 
** Started on  Sun May 21 18:01:20 2017 Leo Maignan
** Last update Sun May 21 23:10:26 2017 Senpai
*/

#include "execution.h"

int	exec_second_command(t_command **commands, char **envp,
			    char **newtab, pid_t pid)
{
  (void)commands;
  int	signal;

  if (pid == 0)
    {
      if (execvpe(newtab[0], newtab, envp) == -1)
	{
	  perror(newtab[0]);
	  exit(1);
	}
    }
  else if (pid != 0)
    wait(&signal);
  return (signal);
}

int	and_command(char **args, t_command **command, char **envp)
{
  pid_t	pid;
  int	signal;
  int	check;
  char **newtab;

  check = 0;
  newtab = list_to_tab((*command)->next->args);
  *command = consume_command(*command, 2);
  if ((pid = fork()) == -1)
    return (EXEC_ERROR);
  if (pid == 0)
    {
      if (execvpe(args[0], args, envp) == -1)
	{
	  perror(args[0]);
     	  check = 1;
	}
      if (check != 1)
	signal = exec_second_command(command, envp, newtab, pid);
      if (check == 1)
	exit(1);
    }
  else if (pid != 0)
    wait(&signal);
  return (signal);
}

int	or_command(char **args, t_command **command, char **envp)
{
  pid_t	pid;
  int	signal;
  char **newtab;

  signal = 0;
  newtab = list_to_tab((*command)->next->args);
  *command = consume_command(*command, 2);
  if ((pid = fork()) == -1)
    return (EXEC_ERROR);
  if (pid == 0)
    {
      if (execvpe(args[0], args, envp) == -1)
	{
	  perror(args[0]);
	  signal = exec_second_command(command, envp, newtab, pid);
	  exit(1);
	}
    }
  else if (pid != 0)
    wait(&signal);
  return (signal);
}
