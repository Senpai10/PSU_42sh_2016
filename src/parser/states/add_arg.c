/*
** add_arg.c for 42sh in /home/pierre/PSU/PSU_2016_42sh/src/parser
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Wed Apr 26 19:49:03 2017 Pierre J. Alderman
** Last update Sun May 21 22:26:46 2017 Pierre J. Alderman
*/

#include "parser.h"

/*
** add_args adds the argument to the argument list, changes args_it and
** and checks fors alias
*/
t_command      	*state_add_arg(char *str, t_command *commands,
			       void *states, t_env *envp)
{
  t_arg		*arg_tmp;
  t_command	*alias;

  if (commands->args_it->arg == NULL)
    return (p_tokenizer(str + 1, commands, states, envp));
  if (commands->args_it->prev == NULL &&
      (alias = p_get_alias(commands->args_it->arg, envp)) != NULL)
    commands = p_append_command(alias, commands);
  else
    commands->nb_args += 1;
  arg_tmp = commands->args_it;
  commands->args_it = init_t_arg();
  if (commands->args_it == NULL)
    return (NULL);
  arg_tmp->next = commands->args_it;
  commands->args_it->prev = arg_tmp;
  return (p_tokenizer(str + 1, commands, states, envp));
}
