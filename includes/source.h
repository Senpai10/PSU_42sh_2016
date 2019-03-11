/*
** source.h for 42sh in /home/zahut/rendu/PSU/PSU_2016_42sh/includes
** 
** Made by Thibault Hebert
** Login   <thibault.hebert@epitech.eu>
** 
** Started on  Wed May  3 11:34:47 2017 Thibault Hebert
** Last update Wed May  3 13:37:01 2017 Thibault Hebert
*/

#ifndef SOURCE_H_
# define SOURCE_H_

#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdarg.h>
#include <ncurses.h>
#include "builtins.h"
#include "ftsh.h"
#include "input.h"
#include "my.h"
#include "parser.h"

#define LINE (0)
#define NO_LINE (1)
#define READ_SIZE (6)

#endif /* SOURCE_H */
