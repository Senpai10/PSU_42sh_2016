/*
** utils.c for minishell2 in /home/zahut/rendu/PSU/PSU_2016_minishell2/src
** 
** Made by Thibault Hebert
** Login   <thibault.hebert@epitech.eu>
** 
** Started on  Thu Mar 23 18:35:41 2017 Thibault Hebert
** Last update Sun May 21 22:52:18 2017 Leo Maignan
*/

#include "execution.h"

int	list_len_command(t_arg *arg)
{
  t_arg	*elem;
  int	it;

  it = 0;
  elem = arg;
  while (elem != NULL)
    {
      elem = elem->next;
      it++;
    }
  return (it);
}

char	**list_to_tab(t_arg *arg)
{
  char	**arg_tab;
  t_arg	*new_arg;
  int	it;

  new_arg = arg;
  if ((arg_tab = malloc(sizeof(char *)
			* (list_len_command(arg) + 1))) ==  NULL)
    return (NULL);
  it = 0;
  while (new_arg->next != NULL)
    {
      arg_tab[it] = strdup(new_arg->arg);
      new_arg = new_arg->next;
      it++;
    }
  arg_tab[it] = strdup(new_arg->arg);
  arg_tab[it + 1] = NULL;
  return (arg_tab);
}
