#include "ft_ls.h"

int  arg_check(int ac, char **av)
{
  int i;

  i = -1;
  while (++i < ac)
  {
    if (av[i][0] == '-')
      return (0);
  }
  return (1);
}
