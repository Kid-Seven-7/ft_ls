#include "libft.h"


/* A very basic structure that can currently read files and folders in a 
 ** store them in the *dir struct directory (not in alphabetical order) 
 ** and not much else */
int main(void)
{
  DIR             *d;
  struct dirent   *dir;
  int             i;
  char            *str;

  d = opendir(".");
  i = -1;
  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    {
      //TODO place all the names into a 2d array for sorting
      i++;
      str = dir->d_name;
    }
    closedir(d);
  }
  return (0);
}
