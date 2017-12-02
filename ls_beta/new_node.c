#include "ft_ls.h"

void        		ids(t_filedata **list, struct stat stats)
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

char				*convert_permissions(struct stat stats)
{
	char			*permissions;

	permissions = (char *)malloc(11);
	permissions[10] = '\0';
	permissions[1] = *((stats.st_mode & S_IRUSR) ? "r" : "-");
	permissions[2] = *((stats.st_mode & S_IWUSR) ? "w" : "-");
	permissions[3] = *((stats.st_mode & S_IXUSR) ? "x" : "-");
	permissions[4] = *((stats.st_mode & S_IRGRP) ? "r" : "-");
	permissions[5] = *((stats.st_mode & S_IWGRP) ? "w" : "-");
	permissions[6] = *((stats.st_mode & S_IXGRP) ? "x" : "-");
	permissions[7] = *((stats.st_mode & S_IROTH) ? "r" : "-");
	permissions[8] = *((stats.st_mode & S_IWOTH) ? "w" : "-");
	permissions[9] = *((stats.st_mode & S_IXOTH) ? "x" : "-");
	return (permissions);
}

void        		general(t_filedata **list, struct stat stats)
{
	(*list)->timestamp = ctime(&stats.st_mtime);
	(*list)->size = stats.st_size;
	(*list)->links = stats.st_nlink;
	(*list)->permissions = convert_permissions(stats);
}

t_filedata			*new_node(struct dirent *dir)
{
	t_filedata		*list;
	struct stat 	stats;

	list = NULL;
	if (stat(dir->d_name, &stats) == 0)
	{
		//list = NULL;
		if (!(list = (t_filedata *)malloc(sizeof(t_filedata))))
			return (NULL);
		ft_bzero(list, sizeof(t_filedata));
		list->name = (dir)->d_name;
		general(&list, stats);
		ids(&list, stats);
		list->permissions[0] = *((dir->d_type == 4) ? "d" : "-");
		list->sub = NULL;
		list->next = NULL;
	}
	return (list);
}
