#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
# include <sys/stat.h>
# include <sys/types.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>

typedef struct      s_filedata
{
  char              *name;
  char              *timestamp;
  char              *uid;
  char              *gid;
  long int          size;
  unsigned long int links;
  unsigned int      permissions;
  struct s_filedata *sub;
  struct s_filedata *next;
}                   t_filedata;

int                 arg_check(int ac, char **av);
t_filedata	        *ft_lstadd_to_head(struct dirent *dir, t_filedata *list);
void	              read_into_dir(void);
void	              sub(char * str);
t_filedata	        *new_node(struct dirent *dir);

#endif
