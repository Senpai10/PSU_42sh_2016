/*
** test_main.c for 42sh in /home/pierre/PSU/PSU_2016_42sh/src/parser
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Thu Apr 27 14:48:41 2017 Pierre J. Alderman
** Last update Tue May  2 19:23:36 2017 Pierre J. Alderman
*/

#include "ftsh.h"

int	main(int ac, char **av, char **envp)
{
  t_command	*commands;

  if (ac != 2)
    return (0);
  commands = parser(av[1], envp);
  print_commands(commands);
  if (commands == NULL)
    return (0);
  return (0);
}
