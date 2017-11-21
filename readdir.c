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
#include <time.h>

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
	t_list			*head;

	struct stat		foo;

	d = opendir(".");
	head = NULL;
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
			printf("uid: %u\n", foo.st_uid);
			printf("gid: %u\n", foo.st_gid);
			printf("size: %lld\n", foo.st_size);
			printf("link: %hu\n", foo.st_nlink);
			printf("mode: %hu\n", foo.st_mode);
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
			printf("uid: %u\n", foo.st_uid);
			printf("gid: %u\n", foo.st_gid);
			printf("size: %lld\n", foo.st_size);
			printf("link: %hu\n", foo.st_nlink);
			printf("mode: %hu\n", foo.st_mode);
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
