/*
** create_env.c for 42sh in /home/zahut/rendu/PSU/PSU_2016_42sh/src/builtins/utils
** 
** Made by Thibault Hebert
** Login   <thibault.hebert@epitech.eu>
** 
** Started on  Wed May  3 18:35:39 2017 Thibault Hebert
** Last update Mon May 15 15:43:28 2017 Pierre J. Alderman
*/

#include "builtins.h"

t_evar		*create_home_elem(char	*username)
{
  t_evar	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (NULL);
  if ((elem->name = strdup("HOME")) == NULL)
    return (NULL);
  if ((elem->data = create_home(username)) == NULL)
    return (NULL);
  return (elem);
}

t_evar		*create_pwd_elem(char *home)
{
  t_evar	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (NULL);
  if ((elem->name = strdup("PWD")) == NULL)
    return (NULL);
  if ((elem->data = create_pwd(home)) == NULL)
    return (NULL);
  return (elem);
}

t_evar		*create_username_elem()
{
  t_evar	*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (NULL);
  if ((elem->name = strdup("USER")) == NULL)
    return (NULL);
  if ((elem->data = take_username()) == NULL)
    return (NULL);
  return (elem);
}

t_evar		*create_env()
{
  t_evar	*username;
  t_evar	*home;
  t_evar	*pwd;

  if ((username = create_username_elem()) == NULL)
    return (NULL);
  if ((home = create_home_elem(username->data)) == NULL)
    return (NULL);
  if ((pwd = create_pwd_elem(home->data)) == NULL)
    return (NULL);
  username->prev = NULL;
  username->next = pwd;
  pwd->prev = username;
  pwd->next = home;
  home->prev = pwd;
  home->next = NULL;
  if (add_new_elem("OLDPWD", NULL, username) == EXEC_ERROR)
    return (NULL);
  return (username);
}
