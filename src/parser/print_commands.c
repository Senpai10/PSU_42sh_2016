/*
** print_commands.c for 42sh in /home/pierre/PSU/PSU_2016_42sh/src/parser
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Tue May  2 14:35:14 2017 Pierre J. Alderman
** Last update Thu May 11 14:29:07 2017 Pierre J. Alderman
*/

#include "parser.h"
/*
** POUR TEST SEULEMENT!
*/
void		print_commands(t_command *commands_const)
{
  t_command	*commands;
  int	cnt;

  if (commands_const == NULL)
    return ;
  commands = commands_const;
  while (commands)
    {
      printf("command=%s\n", commands->command);
      cnt = 1;
      while (commands->args_it)
	{
	  printf("    arg nb%d=%s\n", cnt, commands->args_it->arg);
	  commands->args_it = commands->args_it->next;
	  ++cnt;
	}
      printf("    state=%d\n", commands->state);
      commands = commands->next;
    }
  commands_const->args_it = commands_const->args;
}
