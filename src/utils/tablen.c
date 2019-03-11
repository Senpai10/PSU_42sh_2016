/*
** tablen.c for 42sh in /home/pierre/PSU/PSU_2016_42sh
** 
** Made by Pierre J. Alderman
** Login   <pierre@epitech.net>
** 
** Started on  Tue May 30 16:04:57 2017 Pierre J. Alderman
** Last update Tue May 30 16:05:07 2017 Pierre J. Alderman
*/

int	tablen(char **tab)
{
  int	i;

  if (!tab)
    return (0);
  i = 0;
  while (tab[i])
    i++;
  return (i);
}
