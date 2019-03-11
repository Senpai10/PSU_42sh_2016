/*
** check_redirect.c for 42sh in /home/senpai/EPITECH/PSU_2016/PSU_2016_42sh
** 
** Made by Senpai
** Login   <charly.dai@epitech.eu>
** 
** Started on  Sun May 21 19:18:57 2017 Senpai
** Last update Mon May 22 01:27:58 2017 Thibault Hebert
*/

#include "execution.h"

int	check_redirect_l_l(char **args, t_command **commands, char **envp)
{
   int   signal;

  if ((*commands)->next->state != STATE_R_REDIR &&
      (*commands)->next->state != STATE_DR_REDIR)
    {
      if ((signal = redirect_l_l(args, commands, envp)) == EXEC_ERROR)
        return (EXEC_ERROR);
    }
  else if ((*commands)->next->state != STATE_DL_REDIR &&
	   (*commands)->next->state != STATE_DR_REDIR)
    {
      if ((signal = redirect_l_l_r(args, commands, envp)) == EXEC_ERROR)
        return (EXEC_ERROR);
    }
  else if ((*commands)->next->state != STATE_DL_REDIR &&
	   (*commands)->next->state != STATE_R_REDIR)
    {
      if ((signal = redirect_l_l_r_r(args, commands, envp)) == EXEC_ERROR)
        return (EXEC_ERROR);
    }
  return (signal);
}

int	check_redirect_r_r(char **args, t_command **commands, char **envp)
{
  int	signal;

  if ((*commands)->next->state != STATE_L_REDIR &&
      (*commands)->next->state != STATE_DL_REDIR)
    {
      if ((signal = redirect_r_r(args, commands, envp)) == EXEC_ERROR)
        return (EXEC_ERROR);
    }
  else if ((*commands)->next->state != STATE_DR_REDIR &&
	   (*commands)->next->state != STATE_DL_REDIR)
    {
      if ((signal = redirect_r_r_l(args, commands, envp)) == EXEC_ERROR)
        return (EXEC_ERROR);
    }
  else if ((*commands)->next->state != STATE_DR_REDIR &&
	   (*commands)->next->state != STATE_L_REDIR)
    {
      if ((signal = redirect_r_r_l_l(args, commands, envp)) == EXEC_ERROR)
        return (EXEC_ERROR);
    }
  return (signal);
}

int     check_redirect_r(char **args, t_command **commands, char **envp)
{
  int   signal;

  if ((*commands)->next->state != STATE_L_REDIR &&
      (*commands)->next->state != STATE_DL_REDIR)
    {
      if ((signal = redirect_r(args, commands, envp)) == EXEC_ERROR)
        return (EXEC_ERROR);
    }
  else if ((*commands)->next->state != STATE_R_REDIR &&
           (*commands)->next->state != STATE_DL_REDIR)
    {
      if ((signal = redirect_r_l(args, commands, envp)) == EXEC_ERROR)
        return (EXEC_ERROR);
    }
  else if ((*commands)->next->state != STATE_R_REDIR &&
           (*commands)->next->state != STATE_L_REDIR)
    {
      if ((signal = redirect_r_l_l(args, commands, envp)) == EXEC_ERROR)
        return (EXEC_ERROR);
    }
  return (signal);
}
