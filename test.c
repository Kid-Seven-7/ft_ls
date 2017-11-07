#include "./libft/libft.h"

int main(void)
{
  DIR             *d;
  struct dirent   *dir;
  int             i;
  char            *str;
  //int             hold;
  //char            **names;

  d = opendir(".");
  i = -1;
  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    {
      //TODO place all the names into a 2d array for sorting
      i++;
      str = dir->d_name;
      printf("%s\ni is %i\n", str, i);
      //printf("%i is %s which is %lu chars long\n", i, dir->d_name, strlen(dir->d_name));
    }
    closedir(d);
  }
  return (0);
}
