/*
** input.h for 42sh in /home/pierre/PSU/PSU_2016_42sh/includes
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Tue May  2 16:04:11 2017 Pierre J. Alderman
** Last update Tue May 30 21:11:52 2017 Matthias Gayaud
*/

#ifndef INPUT_H_
# define INPUT_H_

#include "utils.h"

#define INPUT_NB_STATES 9

#define FTSH_SKIP_STATE 0
#define FTSH_BASIC_CHAR 1
#define FTSH_TAB 2
#define FTSH_BACKSPACE 3
#define FTSH_CTRL_D 4
#define FTSH_KEY_RIGHT 5
#define FTSH_KEY_LEFT 6
#define FTSH_KEY_UP 7
#define FTSH_KEY_DOWN 8

#define RIGHT 1
#define LEFT 2
#define UP 3
#define DOWN 4

typedef struct	s_curs_desc
{
  int	x;
  int	x_bound;
}		t_curs_desc;
#define CURS t_curs_desc

typedef struct	s_machine_params
{
  CURS			*curs;
  struct winsize	w;
  struct termios	terminal;
  char			*terminal_name;
  char			buffer[3];
  int			input;
  char			*cur_str;
}		t_machine_params;

typedef char	*(*t_input_state)(t_machine_params *, void *);

typedef struct	s_input_state_desc
{
  int		id;
  t_input_state	func;
}		t_input_state_desc;
#define ISD t_input_state_desc

char			*input_switcher(t_machine_params *params,
					void *states);
char			*auto_complete(t_machine_params *params, void *states);
char			*skip_state(t_machine_params *params, void *states);
char			*return_str(t_machine_params *params);
char			*mv_curs_r(t_machine_params *params, void *states);
char			*mv_curs_l(t_machine_params *params, void *states);
char			*prev_str(t_machine_params *params, void *states);
char			*next_str(t_machine_params *params, void *states);
char			*del_token(t_machine_params *params, void *states);
char			*add_token(t_machine_params *params, void *states);
char			*refresh_display(int step, t_machine_params *params,
					 void *states);
char			*change_bound(int step, t_machine_params *params,
				      void *states);
void			mv_curs(int direction, int step,
				 t_machine_params *params);
char			*try_exit(t_machine_params *params, void *states);
void			free_states(ISD *states);
int			free_params(t_machine_params *params);
t_machine_params	*init_machine_params();
int			get_pressed_key(char *str);

#endif
/*
** INPUT_H_
*/
