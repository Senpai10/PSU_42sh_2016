/*
** exec_commands.c for 42sh in /home/pierre/PSU/PSU_2016_42sh
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Thu May 11 16:14:20 2017 Pierre J. Alderman
** Last update Sun May 21 20:30:59 2017 Thibault Hebert
*/

#include "execution.h"

static t_exec_state	get_state(t_exe_state state,
				  const t_exec_state_desc *states)
{
  int			i;

  i = 0;
  while (i < EXEC_NB_STATES)
    {
      if (states[i].state == state)
	return (states[i].func);
      ++i;
    }
  return (exec_reg);
}

int		exec_commands(t_command *commands, char **envp,
			      int exe, t_exec_state_desc *states)
{
  t_exec_state	state;
  char		**args;

  if (commands == NULL)
    return (exe);
  args = list_to_tab(commands->args);
  state = get_state(commands->state, states);
  exe = state(args, &commands, envp);
  return (exec_commands(commands, envp, exe, states));
}
