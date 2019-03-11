/*
** p_job_or_and.c for 42sh in /home/pierre/PSU/PSU_2016_42sh/src/parser
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Thu May  4 17:10:42 2017 Pierre J. Alderman
** Last update Sat May 20 17:49:37 2017 Pierre J. Alderman
*/

#include "parser.h"

t_command	*p_job_or_and(char *str, t_command *commands,
			      void *states, t_env *envp)
{
  int	exe;

  exe = P_DOUBLE_TOKEN(str);
  if (exe == 2)
    commands = state_add_command(commands, STATE_AND);
  return (p_tokenizer(str + exe, commands, states, envp));
}
