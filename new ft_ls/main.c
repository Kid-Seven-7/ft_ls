#include "ft_ls.h"

int main(int ac, char **av)
{
  if (ac >1)
  {
    printf("%i\n", arg_check(ac, av));
    if (arg_check(ac, av) == 0)
      read_into_dir();
    else
      ft_putendl("invalid");
  }
  else
    read_into_dir();
  return (0);
}
