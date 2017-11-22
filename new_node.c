/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 11:46:42 by jngoma            #+#    #+#             */
/*   Updated: 2017/11/22 12:20:31 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_filedata		*new_node(struct dirent *dir)
{
	struct passwd		*user;
	struct group		*grp;
	struct stat			*stats;
	t_filedata			*list;

	list = NULL;
	stats = NULL;
	if (!(list = (t_filedata *)malloc(sizeof(t_filedata))))
		return (NULL);
	stat(dir->d_name, stats);
	list->name = dir->d_name;
	list->timestamp = ctime(&stats->st_mtime);
	user = getpwuid(stats->st_uid);
	list->uid = user->pw_name;
	grp = getgrgid(stats->st_gid);
	list->gid = grp->gr_name;
	list->size = stats->st_size;
	list->links = stats->st_nlink;
	list->permissions = stats->st_mode;
	if (dir->d_type == 4)
		list->sub = NULL;
	else
		list->sub = NULL;
	list->next = NULL;
	return (list);
}
