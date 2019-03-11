/*
** get_states.c for 42sh in /home/pierre/PSU/PSU_2016_42sh
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Thu May 11 17:01:16 2017 Pierre J. Alderman
** Last update Sun May 21 23:06:47 2017 Senpai
*/

#include "execution.h"

t_exec_state_desc	*get_states()
{
  t_exec_state_desc	*states;

  if ((states = malloc(sizeof(*states) * EXEC_NB_STATES))
      == NULL)
    return (NULL);
  states[0].state = STATE_L_REDIR;
  states[0].func = redirect_l;
  states[1].state = STATE_DL_REDIR;
  states[1].func = check_redirect_l_l;
  states[2].state = STATE_R_REDIR;
  states[2].func = check_redirect_r;
  states[3].state = STATE_DR_REDIR;
  states[3].func = check_redirect_r_r;
  states[4].state = STATE_PIPE;
  states[4].func = pipe_command;
  states[5].state = STATE_OR;
  states[5].func = or_command;
  states[6].state = STATE_AND;
  states[6].func = and_command;
  return (states);
}
