#include "ft_ls.h"

void  valid_parmas(char *params, int i)
{
  while (params[++i])
  {
    if (params[i] == 'R')
      valid_parmas(params, i);
    else if (params[i] == 'a')
      valid_parmas(params, i);
    else if (params[i] == 'l')
      valid_parmas(params, i);
    else if (params[i] == 'r')
      valid_parmas(params, i);
    else if (params[i] == 't')
      valid_parmas(params, i);
    else
    {
      ft_putstr("ls: illegal option -- ");
      ft_putchar(params[i]);
      ft_putstr("\nusage: ls [-Ralrt] [file ...]\n");
      exit (1);
    }
  }
}
