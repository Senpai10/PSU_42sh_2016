/*
** get_env_info.c for 42sh in /home/zahut/rendu/PSU/PSU_2016_42sh/src/builtins/utils
** 
** Made by Thibault Hebert
** Login   <thibault.hebert@epitech.eu>
** 
** Started on  Thu Apr 27 18:38:58 2017 Thibault Hebert
** Last update Mon May 15 15:46:59 2017 Pierre J. Alderman
*/

#include "builtins.h"

char	*create_pwd(char *home)
{
  char	*pwd;

  if ((pwd = getcwd(NULL, 0)) == NULL)
    {
      fprintf(stderr, "%s\n", strerror(errno));
      if ((pwd = strdup(home)) == NULL)
	{
	  fprintf(stderr, "%s\n", strerror(errno));
	  return (NULL);
	}
    }
  return (pwd);
}

char	*create_home(char *username)
{
  char	*home;

  if ((home = my_strcat("/home/", username)) == NULL)
    return (NULL);
  else
    return (home);
}

char		*take_username()
{
  uid_t		uid;
  struct passwd	*info;

  uid = getuid();
  if ((info = getpwuid(uid)) == NULL)
    {
      fprintf(stderr, "%s\n", strerror(errno));
      return (NULL);
    }
  return (info->pw_name);
}
