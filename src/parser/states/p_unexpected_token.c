/*
** p_unexpected_token.c for 42sh in /home/pierre/PSU/PSU_2016_42sh/src/parser
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Thu May  4 15:16:45 2017 Pierre J. Alderman
** Last update Sat May 20 17:38:39 2017 Pierre J. Alderman
*/

#include "parser.h"

t_command	*p_unexpected_token(char c)
{
  printf("42sh: Error: unexpected token near '%c'\n", c);
  return (NULL);
}
