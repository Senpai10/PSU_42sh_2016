/*
** main.c for 42sh in /home/pierre/PSU/PSU_2016_42sh
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Mon May 15 16:26:23 2017 Pierre J. Alderman
** Last update Tue May 30 19:27:48 2017 Matthias Gayaud
*/

#include "ftsh.h"

int	main(int ac, char **av, char **envp)
{
  (void)ac;
  (void)av;
  return (start_ftsh(envp));
}
