/*
** mv_curs.c for 42sh in /home/Matthy/PSU_2016_42sh/src/curs
** 
** Made by Matthias Gayaud
** Login   <Matthy@epitech.net>
** 
** Started on  Wed May  3 11:54:52 2017 Matthias Gayaud
** Last update Tue May 30 18:31:21 2017 Matthias Gayaud
*/

#include "input.h"

int	intchar(int c)
{
  my_putchar(c);
  return (0);
}

void	mv_curs_side(int step, char *direction)
{
  int	i;

  i = 0;
  while (i++ < step)
    tputs(tgoto(direction, 0, 0), 1, intchar);
}

void	mv_curs(int direction, int step, t_machine_params *params)
{
  char	*right;
  char	*left;
  char	*up;
  char	*down;
  int	i;

  i = 0;
  right = tgetstr("nd", NULL);
  left = tgetstr("le", NULL);
  up = tgetstr("up", NULL);
  down = tgetstr("do", NULL);
  if (direction == RIGHT)
    mv_curs_side(step, right);
  if (direction == LEFT)
    mv_curs_side(step, left);
  if (direction == UP)
    {
      tputs(tgoto(up, 0, 0), 1, intchar);
      while (i++ < params->w.ws_col)
	tputs(tgoto(right, 0, 0), 1, intchar);
    }
  if (direction == DOWN)
    tputs(tgoto(down, 0, 0), 1, intchar);
}
