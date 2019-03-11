/*
** parser.h for 42sh in /home/pierre/PSU/PSU_2016_42sh/src/parser
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Thu Apr 27 13:28:22 2017 Pierre J. Alderman
** Last update Sun May 21 22:52:45 2017 Pierre J. Alderman
*/

#ifndef PARSER_H_
# define PARSER_H_

#include "utils.h"

#define STEP 1
#define END_OF_DIGEST(A) (A == 0)
#define P_DOUBLE_TOKEN(A) (*A == 0 ? 1 : (*A == *(A + 1) ? 2 : 1))

typedef t_command *(*t_state_func)(char *, t_command *, void *, t_env *);

typedef  struct	s_state
{
  int		id;
  t_state_func	function;
}		t_state;

#define NB_STATES 11
/*
** parser states
*/
t_command      	*state_add_arg(char *str, t_command *commands,
			       void *states, t_env *envp);
t_command      	*p_tokenizer(char *str, t_command *commands,
			     void *states, t_env *envp);
t_command      	*state_catch_litteral_str(char *str, t_command *commands,
					  void *states, t_env *envp);
t_command      	*state_add_home(char *str, t_command *commands,
				void *states, t_env *envp);
t_command      	*state_catch_str(char *str, t_command *commands,
				 void *states, t_env *envp);
t_command      	*state_catch_parenthesis(char *str, t_command *commands,
					 void *states, t_env *envp);
t_command      	*state_wild_card(char *str, t_command *commands,
				 void *states, t_env *envp);
t_command      	*state_semicolon(char *str, t_command *commands,
				 void *states, t_env *envp);
t_command      	*p_add_token(char *str, t_command *commands,
			     void *states, t_env *envp);
t_command      	*p_pipe_or_or(char *str, t_command *commands,
		      void *states, t_env *envp);
t_command      	*p_job_or_and(char *str, t_command *commands,
		      void *states, t_env *envp);
t_command	*state_add_command(t_command *commands,
				   t_exe_state state);
t_command      	*p_end_of_digest(t_command *commands, t_env *envp);
t_command      	*p_unexpected_token(char c);
t_command      	*p_r_redir(char *str, t_command *commands,
			   void *states, t_env *envp);
t_command      	*p_l_redir(char *str, t_command *commands,
			   void *states, t_env *envp);

t_command	*p_get_alias(char *str, t_env *env);

t_command	*p_append_command(t_command *elem,
				  t_command *commands);

t_command	*p_ignore(char *str, t_command *commands,
		  void *states, t_env *env);

t_command	*p_dup_command(t_command *p);

t_arg		*init_t_arg();
t_command	*init_t_command();
void		burn_arg(t_command *commands);
void		burn_commands(t_command *commands_const);

#endif
/*
** PARSER_H_
*/
