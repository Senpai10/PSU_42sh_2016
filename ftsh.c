/*
** ftsh.c for 42sh in /home/pierre/PSU/PSU_2016_42sh
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Mon May 15 16:29:44 2017 Pierre J. Alderman
** Last update Wed May 31 09:18:35 2017 Matthias Gayaud
*/

#include "ftsh.h"

int	ftsh(t_env *env, char **envp,
	     t_exec_state_desc *states,
	     int signal)
{
  char		*line;
  t_command	*commands;

  my_putstr("42sh $> ");
  if ((line =  get_input(0)) == NULL)
    {
      printf("exit\n");
      return (signal);
    }
  if ((commands = parser(line, env)) != NULL)
    {
      if ((signal = check_builtins(list_to_tab(commands->args), env)) == ERROR)
	signal = exec_commands(commands, envp, signal, states);
    }
  return (ftsh(env, envp, states, signal));
}

int	init_env(t_env *env, char **envp)
{
  env->envp = envp;
  if ((env->env = take_env(envp)) == NULL)
    return (1);
  env->alias = NULL;
  env->lvar = NULL;
  return (0);
}

int			start_ftsh(char **envp)
{
  t_env			env;
  t_exec_state_desc	*states;

  if ((init_env(&env, envp)) == 1)
    return (84);
  if ((states = get_states()) == NULL)
    return (84);
  init_ftsh(&env, envp, states);
  return (ftsh(&env, envp, states, 0));
}
