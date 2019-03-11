/*
** exec.c for 42sh in /home/senpai/EPITECH/PSU_2016/PSU_2016_42sh
** 
** Made by Senpai
** Login   <charly.dai@epitech.eu>
** 
** Started on  Thu May 11 17:23:34 2017 Senpai
** Last update Mon May 22 01:32:02 2017 Thibault Hebert
*/

#include "execution.h"

static void    check_status(int *status)
{
  int	check;

  check = 0;
  if (WIFEXITED(*status))
    *status = WEXITSTATUS(*status);
  else if (WIFSIGNALED(*status))
    check = WTERMSIG(*status);
  if (check == SIGSEGV)
    {
      printf("Segmentation fault%s\n",
	     WCOREDUMP(*status) ? " (core dumped)" : "");
      *status = 139;
    }
  else if (check == SIGFPE)
    {
      printf("Floating exception%s\n",
	     WCOREDUMP(*status) ? " (core dumped)" : "");
      *status = 136;
    }
}

int    fork_exec(char **args, char **envp)
{
  pid_t pid;
  int	signal;

  signal = 0;
  if ((pid = fork()) == -1)
    return (EXEC_ERROR);
  if (pid == 0)
    {
      if ((execvpe(args[0], args, envp)) == -1)
	fprintf(stderr, "%s: Command not found.\n", args[0]);
      exit(1);
    }
  else if (pid != 0)
    {
      wait(&signal);
      check_status(&signal);
    }
  return (signal);
}
