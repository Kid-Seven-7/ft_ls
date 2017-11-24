#include "ft_ls.h"

void        ids(t_filedata **list, struct stat stats)
{
  struct passwd	*user;
	struct group	*grp;

  user = getpwuid(stats.st_uid);
  (*list)->uid = (char *)malloc(ft_strlen((char *)user->pw_name));
  (*list)->uid = user->pw_name;
  grp = getgrgid(stats.st_gid);
  (*list)->gid = (char *)malloc(ft_strlen((char *)grp->gr_name));
  (*list)->gid = grp->gr_name;
}

void        general(t_filedata **list, struct stat stats)
{
  (*list)->timestamp = (char *)malloc(ft_strlen(ctime(&stats.st_mtime)));
  (*list)->timestamp = ctime(&stats.st_mtime);
  (*list)->size = (long int)malloc(sizeof(long int));
  (*list)->size = stats.st_size;
  (*list)->links = (unsigned long int)malloc(sizeof(unsigned long int));
  (*list)->links = stats.st_nlink;
  (*list)->permissions = (unsigned int)malloc(sizeof(unsigned int));
  (*list)->permissions = stats.st_mode;
}

t_filedata	*new_node(struct dirent *dir)
{
	t_filedata	*list;
  struct stat stats;

  stat(dir->d_name, &stats);
	list = NULL;
	if (!(list = (t_filedata *)malloc(sizeof(t_filedata))))
		return (NULL);
  list->name = (char *)malloc(ft_strlen((char *)dir->d_name));
	list->name = dir->d_name;
  general(&list, stats);
	list->next = NULL;
	return (list);
}
