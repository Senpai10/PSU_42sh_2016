/*
** check_is_builtins.c for 42sh in /home/zahut/rendu/PSU/PSU_2016_42sh/src/builtins
** 
** Made by Thibault Hebert
** Login   <thibault.hebert@epitech.eu>
** 
** Started on  Tue May  2 15:42:26 2017 Thibault Hebert
** Last update Sun May 21 18:16:26 2017 Pierre J. Alderman
*/

#include "builtins.h"

int     check_builtins2(char **command, t_env *env)
{
  if (strcmp(command[0], "exit") == SUCESS)
    {
      my_exit(command, env);
      return (SUCESS);
    }
  if (strcmp(command[0], "export") == SUCESS)
    {
      export(env, command);
      return (SUCESS);
    }
  if (strcmp(command[0], "alias") == SUCESS)
    {
      alias(env, command);
      return (SUCESS);
    }
  if (strcmp(command[0], "echo") == SUCESS)
    {
      ftsh_echo(command);
      return (SUCESS);
    }
  return (ERROR);
}

int     check_builtins(char **command, t_env *env)
{
  int   signal;

  if (strcmp(command[0], "env") == SUCESS)
    {
      signal = my_env(env, command);
      return (signal);
    }
  else if (strcmp(command[0], "unsetenv") == SUCESS)
    {
      signal = my_unsetenv(env, command);
      return (signal);
    }
  else if (strcmp(command[0], "setenv") == SUCESS)
    {
      signal = my_setenv(env, command);
      return (signal);
    }
  else if (strcmp(command[0], "cd") == SUCESS)
    {
      signal = my_cd(env, command);
      return (signal);
    }
  else if (check_builtins2(command, env) == SUCESS)
    return (SUCESS);
  return (ERROR);
}
