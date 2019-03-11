/*
** reg_command.c for 42sh in /home/pierre/PSU/PSU_2016_42sh
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Fri May 12 11:27:35 2017 Pierre J. Alderman
** Last update Sat May 13 15:27:48 2017 Leo Maignan
*/

#include "execution.h"

int	exec_reg(char **args, t_command **commands, char **envp)
{
  *commands = consume_command(*commands, 1);
  return (fork_exec(args, envp));
}
