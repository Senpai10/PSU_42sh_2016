/*
** exec_cd.c for 42sh in /home/zahut/rendu/PSU/PSU_2016_42sh/src/builtins
** 
** Made by Thibault Hebert
** Login   <thibault.hebert@epitech.eu>
** 
** Started on  Thu Apr 27 12:20:39 2017 Thibault Hebert
** Last update Sun May 21 23:47:18 2017 Thibault Hebert
*/

#include "builtins.h"

int		do_home(t_evar *env)
{
  uid_t		uid;
  struct passwd	*info;
  char		*line;

  uid = getuid();
  if ((info = getpwuid(uid)) == NULL)
    return (EXEC_ERROR);
  if ((line = strdup(info->pw_name)) == NULL)
    return (EXEC_ERROR);
  if ((line = my_strcat("/home/", line)) == NULL)
    return (EXEC_ERROR);
  if (add_new_elem("HOME", line, env) == EXEC_ERROR)
    return (EXEC_ERROR);
  return (SUCESS);
}

int		modif_env(t_evar *env, char *oldpwd)
{
  t_evar	*tmp;

  if ((tmp = find_in_env("OLDPWD", env)) == NULL)
    return (BUILTINS_ERROR);
  if ((tmp->data = strdup(oldpwd)) == NULL)
    {
      fprintf(stderr, "%s\n", strerror(errno));
      return (BUILTINS_ERROR);
    }
  if ((tmp = find_in_env("PWD", env)) == NULL)
    return (BUILTINS_ERROR);
  if ((tmp->data = getcwd(NULL, 0)) == NULL)
    {
      fprintf(stderr, "%s\n", strerror(errno));
      return (BUILTINS_ERROR);
    }
  return (SUCESS);
}

int	exec_cd2(t_evar *env, char *path, char *oldpwd)
{
  if (chdir(path) == ERROR)
    {
      fprintf(stderr, "%s\n", strerror(errno));
      return (BUILTINS_ERROR);
    }
  if (modif_env(env, oldpwd) == BUILTINS_ERROR)
    return (BUILTINS_ERROR);
  return (SUCESS);
}

int		exec_cd(t_evar *env, char **command)
{
  t_evar	*tmp;
  char		*new_oldpwd;
  char		*path;

  if ((tmp = find_in_env("HOME", env)) == NULL)
    {
      if (do_home(env) == EXEC_ERROR)
	return (EXEC_ERROR);
    }
  if ((new_oldpwd = getcwd(NULL, 0)) == NULL)
    {
      fprintf(stderr, "%s\n", strerror(errno));
      return (BUILTINS_ERROR);
    }
  if (command[1] == NULL)
    {
      if ((path = strdup(tmp->data)) == NULL)
	return (BUILTINS_ERROR);
    }
  else
    if ((path = strdup(command[1])) == NULL)
      return (BUILTINS_ERROR);
  return (exec_cd2(env, path, new_oldpwd));
}
