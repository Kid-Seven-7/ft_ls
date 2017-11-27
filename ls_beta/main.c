#include "ft_ls.h"

int main(int ac, char **av)
{
  if (ac > 1)
  {
    if (!arg_check(ac, av))
    {
      ft_putstr(av[1]);
      ft_putstr(":");
      ft_putendl(" No such file or directory");
      return (1);
    }
  }
  read_into_dir();
  return (0);
}
