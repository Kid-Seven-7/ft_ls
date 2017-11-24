#include "ft_ls.h"

t_filedata  *new_node(struct dirent *dir, struct passwd *user, struct group *grp, struct stat *stats)
{
  t_filedata  *list;

  list = NULL;
  if (dir != NULL && user != NULL && group != NULL && stats != NULL)
  {
    if (!(list = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
    list->name = (char *)malloc(ft_strlen(dir->d_name));
    list->name = ft_memcpy(list->name, dir->d_name);
    list->timestamp = (char *)malloc(ft_strlen(ctime(stats.st_mtime)));
    list->timestamp = ft_memcpy(list->timestamp, ctime(stats.st_mtime));
    list->uid = (char *)malloc(ft_strlen(user->pw_name));
    list->uid = ft_memcpy(list->uid, user->pw_name);
    list->gid = (char *)malloc(ft_strlen(grp->gr_nam));
    list->gid = ft_memcpy(list->gid, grp->gr_nam);
    list->size = (long int)malloc(sizeof(long int));
    list->size = stats.st_size;
    list->links = (unsigned long int)malloc(sizeof(unsigned long int));
    list->links = stats.st_nlink;
    list->permissions = (unsigned int)malloc(sizeof(unsigned int));
    list->permissions = stats.st_mode;
    list->sub = (t_filedata)malloc(t_filedata);
    list->sub = NULL;
    list->next = (t_filedata)malloc(t_filedata);
    list->next = NULL;
  }
}
