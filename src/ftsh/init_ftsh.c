/*
** init_ftsh.c for 42sh in /home/pierre/PSU/PSU_2016_42sh/src
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Wed May 17 10:34:41 2017 Pierre J. Alderman
** Last update Wed May 17 10:48:52 2017 Pierre J. Alderman
*/

#include "ftsh.h"

int	init_ftsh(t_env *env, char **envp,
		  t_exec_state_desc *states)
{
  FILE	*fp;

  if ((fp = fopen(".bashrc", "r")) == NULL)
    return (-1);
  exec_from_file(fp, env, envp, states);
  fclose(fp);
  return (0);
}
