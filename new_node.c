/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:32:55 by jngoma            #+#    #+#             */
/*   Updated: 2018/08/17 12:56:35 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char				*my_time(struct stat stats)
{
	char	*my_time;
	int		i;
	char	*temp;

	i = -1;
	my_time = (char *)malloc(12);
	my_time[12] = '\0';
	temp = ctime(&stats.st_mtime);
	temp[16] = '\0';
	while (temp[++i + 4] != '\0')
		my_time[i] = temp[i + 4];
	return (my_time);
}

void				ids(t_fdata **list, struct stat stats)
{
	struct passwd	*user;
	struct group	*grp;

	user = getpwuid(stats.st_uid);
	(*list)->uid = ft_strdup(user->pw_name);
	grp = getgrgid(stats.st_gid);
	(*list)->g_id = stats.st_gid;
	(*list)->gid = ft_strdup(grp->gr_name);
}

char				*convert_permissions(struct stat stats)
{
	char			*permissions;

	permissions = (char *)malloc(12);
	ft_bzero(permissions, 12);
	permissions[0] = *((stats.st_mode & S_IFDIR) ? "d" : "-");
	permissions[1] = *((stats.st_mode & S_IRUSR) ? "r" : "-");
	permissions[2] = *((stats.st_mode & S_IWUSR) ? "w" : "-");
	permissions[3] = *((stats.st_mode & S_IXUSR) ? "x" : "-");
	permissions[4] = *((stats.st_mode & S_IRGRP) ? "r" : "-");
	permissions[5] = *((stats.st_mode & S_IWGRP) ? "w" : "-");
	permissions[6] = *((stats.st_mode & S_IXGRP) ? "x" : "-");
	permissions[7] = *((stats.st_mode & S_IROTH) ? "r" : "-");
	permissions[8] = *((stats.st_mode & S_IWOTH) ? "w" : "-");
	permissions[9] = *((stats.st_mode & S_IXOTH) ? "x" : "-");
	if ((stats.st_mode & S_IFMT) == S_IFLNK)
		permissions[0] = 'l';
	return (permissions);
}

void				general(t_fdata **list, struct stat stats)
{
	(*list)->timestamp = my_time(stats);
	(*list)->time = stats.st_ctime;
	(*list)->timestamp[24] = '\0';
	(*list)->size = stats.st_size;
	(*list)->block = stats.st_blocks;
	(*list)->links = stats.st_nlink;
	(*list)->permissions = convert_permissions(stats);
}

t_fdata				*new_node(struct dirent *dir, char *file)
{
	t_fdata			*list;
	struct stat		stats;

	list = NULL;
	if (lstat(file, &stats) == 0)
	{
		if (!(list = (t_fdata *)malloc(sizeof(t_fdata))))
			return (NULL);
		ft_bzero(list, sizeof(t_fdata));
		list->name = (dir)->d_name;
		general(&list, stats);
		ids(&list, stats);
		if (ft_strcmp(dir->d_name, "..") == 0)
			list->permissions[10] = *((dir->d_type == 4) ? "+" : 0);
		if (list->permissions[0] != 'l')
			list->permissions[0] = *((dir->d_type == 4) ? "d" : "-");
		list->sub = NULL;
		list->next = NULL;
	}
	else
		perror(dir->d_name);
	return (list);
}
