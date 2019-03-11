/*
** echo.c for 42sh in /home/pierre/PSU/PSU_2016_42sh/src/builtins
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Sun May 21 16:31:49 2017 Pierre J. Alderman
** Last update Sun May 21 22:30:58 2017 Pierre J. Alderman
*/

#include "builtins.h"

static int	my_getopt2(char *args, char *opt)
{
  ++args;
  while (*args != 0)
    {
      if (*args == 'e')
	opt[0] = 1;
      else if (*args == 'E')
	opt[1] = 1;
      else if (*args == 'n')
	opt[2] = 1;
      else
	{
	  opt[0] = 2;
	  return (1);
	}
      ++args;
    }
  return (0);
}

static t_echo_opt	*my_getopt(char **args)
{
  t_echo_opt		*opt;
  int			i;
  char			opt_t[3];

  i = 0;
  if ((opt = do_malloc(sizeof(*opt))) == NULL)
    return (NULL);
  while (args[i] != NULL && (args)[i][0] == '-')
    {
      if (my_getopt2(args[i], opt_t) != 1)
	{
	  opt->e = opt_t[0];
	  opt->E = opt_t[1];
	  opt->n = opt_t[2];
	  ++opt->jump;
	}
      ++i;
    }
  return (opt);
}

int		ftsh_echo(char **args)
{
  char		*str;
  t_echo_opt	*opt;

  ++args;
  if ((opt = my_getopt(args)) == NULL)
    return (BUILTINS_ERROR);
  args += opt->jump;
  str = strdup("");
  while (*args != NULL)
    {
      str = strcat(realloc(str, strlen(str) + strlen(*args) + 1), *args);
      if (*(args + 1) != NULL)
	str = strcat(realloc(str, strlen(str) + 2), strdup(" "));
      ++args;
    }
  str = (opt->n == 1 ? str :
	 strcat(realloc(str, strlen(str) + 2), strdup("\n")));
  my_putstr(str);
  return (0);
}
