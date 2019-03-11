/*
** cd.c for 42sh in /home/zahut/rendu/PSU/PSU_2016_42sh/src/builtins
** 
** Made by Thibault Hebert
** Login   <thibault.hebert@epitech.eu>
** 
** Started on  Thu Apr 27 12:03:34 2017 Thibault Hebert
** Last update Mon May 15 15:36:39 2017 Pierre J. Alderman
*/

#include "builtins.h"

int		cd_error(char **command)
{
  struct stat	sb;

  if (stat(command[1], &sb) == ERROR)
    {
      printf("la\n");
      fprintf(stderr, "%s: %s\n", command[1], strerror(errno));
      return (BUILTINS_ERROR);
    }
  else if (!S_ISDIR(sb.st_mode))
    {
      fprintf(stderr, "%s: Not a directory.\n", command[1]);
      return (BUILTINS_ERROR);
    }
  return (SUCESS);
}

int		check_argument(t_evar *env, char **command)
{
  t_evar	*pwd;
  t_evar	*old_pwd;
  t_evar	*home;

  home = find_in_env("HOME", env);
  pwd = find_in_env("PWD", env);
  old_pwd = find_in_env("OLDPWD", env);
  if (strcmp(command[1], "-") == SUCESS)
    return (exec_cd2(env, old_pwd->data, pwd->data));
  else if (strcmp(command[1], "--") == SUCESS)
    return (exec_cd2(env, home->data, old_pwd->data));
  else
    return (check_cd(env, command));
}

int	check_cd(t_evar *env, char **command)
{
  int	ret;

  ret = 0;
  if ((cd_error(command)) == BUILTINS_ERROR)
    return (BUILTINS_ERROR);
  else
    ret = exec_cd(env, command);
  return (ret);
}

int	my_cd(t_env *env, char **command)
{
  int	ret;

  ret = 0;
  if (command[1] == NULL)
    {
      ret = exec_cd(ENV, command);
      return (ret);
    }
  else if (command[2] != NULL)
    {
      fprintf(stderr, "cd: Too many arguments.\n");
      return (BUILTINS_ERROR);
    }
  if ((ret = check_argument(ENV, command)) == SUCESS)
    return (ret);
  else
    ret = check_cd(ENV, command);
  return (ret);
}
