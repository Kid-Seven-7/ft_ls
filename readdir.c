/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:06:00 by jngoma            #+#    #+#             */
/*   Updated: 2017/11/21 15:44:16 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

void	sub(char * str)
{
	DIR				*d;
	struct dirent	*dir;
	t_list			*head;
	char			*joined;

	d = opendir(str);
	head = NULL;
	if (d)
	{
		printf("\n./%s:\n", str);
		while ((dir = readdir(d)) != NULL)
		{
			if (head == NULL)
				head = ft_lstnew((char *)dir->d_name,
						ft_strlen((char *)dir->d_name));
			else
				head = ft_lstadd_to_head(head, (char *)dir->d_name);
			if (dir->d_type == 4)
			{
				if (ft_strncmp((char *)dir->d_name, ".", 1) != 0)
				{
					joined = ft_strjoin(str, "/");
					joined = ft_strjoin(joined, (char*)dir->d_name);
					sub(joined);
				}
				else
					printf("%s\n", dir->d_name);
			}
			else
				printf("%s\n", dir->d_name);
		}
		printf("\n");
	}
	closedir(d);
}

void	read_into_dir(void)
{
	DIR				*d;
	struct dirent	*dir;
	struct passwd	*user;
	struct group	*grp;
	t_list			*head;

	struct stat		foo;

	d = opendir(".");
	head = NULL;
	user = NULL;
	if (d)
	{
		while ((dir = readdir(d)) != NULL)
		{
			if (head == NULL)
				head = ft_lstnew((char *)dir->d_name,
						ft_strlen((char *)dir->d_name));
			else
				head = ft_lstadd_to_head(head, (char *)dir->d_name);
			if (dir->d_type == 4)
			{
				//if (ft_strncmp((char *)dir->d_name, ".", 1) != 0)
				//	sub((char *)dir->d_name);
				//else
					//printf("%s\n", dir->d_name);
				{
				stat(dir->d_name, &foo);
			printf("file: %s\n",dir->d_name);
			printf("time access: %s", ctime(&foo.st_atime));
			printf("time modified: %s", ctime(&foo.st_mtime));
			printf("time status: %s", ctime(&foo.st_ctime));
			//printf("uid: %u\n", foo.st_uid);
			user = getpwuid(foo.st_uid);
			printf("uid: %s\n",user->pw_name);
			//printf("gid: %u\n", foo.st_gid);
			grp = getgrgid(foo.st_gid);
			printf("uid: %s\n",grp->gr_name);
			printf("size: %ld\n", foo.st_size);
			printf("link: %lu\n", foo.st_nlink);
			//printf("mode: %u\n", foo.st_mode);
			printf((S_ISDIR(foo.st_mode)) ? "d" : "-");
			printf((foo.st_mode & S_IRUSR) ? "r" : "-");
			printf((foo.st_mode & S_IWUSR) ? "w" : "-");
			printf((foo.st_mode & S_IXUSR) ? "x" : "-");
			printf((foo.st_mode & S_IRGRP) ? "r" : "-");
			printf((foo.st_mode & S_IWGRP) ? "w" : "-");
			printf((foo.st_mode & S_IXGRP) ? "x" : "-");
			printf((foo.st_mode & S_IROTH) ? "r" : "-");
			printf((foo.st_mode & S_IWOTH) ? "w" : "-");
			printf((foo.st_mode & S_IXOTH) ? "x" : "-");
			printf("\n");
				}
			}
			else
				//printf("%s\n", dir->d_name);
			{
			stat(dir->d_name, &foo);
			printf("file: %s\n",dir->d_name);
			printf("time access: %s", ctime(&foo.st_atime));
			printf("time modified: %s", ctime(&foo.st_mtime));
			printf("time status: %s", ctime(&foo.st_ctime));
			//printf("uid: %u\n", foo.st_uid);
			user = getpwuid(foo.st_uid);
			printf("uid: %s\n",user->pw_name);
			//printf("gid: %u\n", foo.st_gid);
			grp = getgrgid(foo.st_gid);
			printf("uid: %s\n",grp->gr_name);
			printf("size: %ld\n", foo.st_size);
			printf("link: %lu\n", foo.st_nlink);
			//printf("mode: %u\n", foo.st_mode);
			printf((S_ISDIR(foo.st_mode)) ? "d" : "-");
			printf((foo.st_mode & S_IRUSR) ? "r" : "-");
			printf((foo.st_mode & S_IWUSR) ? "w" : "-");
			printf((foo.st_mode & S_IXUSR) ? "x" : "-");
			printf((foo.st_mode & S_IRGRP) ? "r" : "-");
			printf((foo.st_mode & S_IWGRP) ? "w" : "-");
			printf((foo.st_mode & S_IXGRP) ? "x" : "-");
			printf((foo.st_mode & S_IROTH) ? "r" : "-");
			printf((foo.st_mode & S_IWOTH) ? "w" : "-");
			printf((foo.st_mode & S_IXOTH) ? "x" : "-");
			printf("\n");
			//printf("time %ld\n", foo.st_atime);
			//printf("time %ld\n", foo.st_atime);
			}
		}

		closedir(d);
		// NEEDS TO BE HANDLED BY A DIFFERENT FUNCTION
		// while (head != NULL)
		// {
		// 	if (head->content != NULL)
		// 		ft_putendl(head->content);
		// 	head = head->next;
		// }
	}
}
