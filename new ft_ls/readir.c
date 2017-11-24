#include "ft_ls.h"

void    read_into_dir(void)
{
  DIR   *d;
  struct  dirent  *dir;
  struct  passwd  *user;
  struct  group   *grp;
  struct  stat    *stats
  t_filedata      head;

  d = opendir(".");
  head = NULL;
  head = init();
  user = NULL;
  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    {
      if (head == NULL)
      {
        head =
      }
    }
  }
}
