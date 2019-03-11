/*
** read_from_file.c for 42sh in /home/pierre/PSU/PSU_2016_42sh
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Wed May 17 10:09:07 2017 Pierre J. Alderman
** Last update Wed May 17 11:30:45 2017 Pierre J. Alderman
*/

#include "ftsh.h"

int		exec_from_file(FILE *fd,
			       t_env *env, char **envp,
			       t_exec_state_desc *states)
{
  ssize_t	size;
  char		*buf;
  t_command	*commands;
  int		signal;
  size_t       	n;

  n = 250;
  if ((buf = malloc(sizeof(*buf) * n)) == NULL)
    return (-1);
  if ((size = getline(&buf, &n, fd)) <= 0)
    return (size);
  buf[size - 1] = 0;
  if ((commands = parser(buf, env)) != NULL)
    {
      if ((signal = check_builtins(list_to_tab(commands->args), env)) == ERROR)
	signal = exec_commands(commands, envp, signal, states);
    }
  return (exec_from_file(fd, env, envp, states));
}
