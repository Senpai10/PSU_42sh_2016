/*
** init_machine_params.c for 42sh in /home/pierre/PSU/PSU_2016_42sh/src/curs
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Tue May  2 21:41:29 2017 Pierre J. Alderman
** Last update Tue May 30 21:11:46 2017 Matthias Gayaud
*/

#include "input.h"

int	init_termcaps(t_machine_params *params)
{
  if ((params->terminal_name = getenv("TERM")) == NULL)
    return (-1);
  if (tgetent(NULL, params->terminal_name) == -1)
    return (-1);
  if (tcgetattr(0, &params->terminal) == -1)
    return (-1);
  params->terminal.c_lflag &= ~(ICANON);
  params->terminal.c_lflag &= ~(ECHO);
  params->terminal.c_cc[VMIN] = 1;
  params->terminal.c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSADRAIN, &params->terminal) == -1)
    return (-1);
  return (0);
}

void	fill_cur_str(char *str, int len)
{
  int	i;

  i = 0;
  while (i < len)
    {
      str[i] = '\0';
      i++;
    }
}

t_machine_params	*init_machine_params()
{
  t_machine_params	*params;

  params = malloc(sizeof(*params));
  if (params == NULL)
    return (NULL);
  params->curs = malloc(sizeof(*params->curs));
  if (params->curs == NULL)
    return (NULL);
  params->curs->x = 0;
  params->curs->x_bound = 0;
  params->input = 0;
  if (init_termcaps(params) == -1)
    return (NULL);
  ioctl(0, TIOCGWINSZ, &params->w);
  if ((params->cur_str = malloc(sizeof(char) * (params->w.ws_col + 1))) == NULL)
    return (NULL);
  fill_cur_str(params->cur_str, params->w.ws_col);
  return (params);
}
