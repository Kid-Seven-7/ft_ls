/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readdir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 09:23:40 by jngoma            #+#    #+#             */
/*   Updated: 2017/11/29 10:36:18 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_filedata			*sub(char *str)
{
	DIR				*sub_d;
	struct dirent	*dir;
	t_filedata		*head;
	char			*joined;

	sub_d = opendir(str);
	head = NULL;
	printf("sub function called\n");
	if (sub_d)
	{
		printf("\ndir with subs is ./%s:\n", str);
		while ((dir = readdir(sub_d)) != NULL)
		{
			printf("before head init\n");
			if (head == NULL)
			{
				printf("head is null\n");
				head = new_node(dir);
			}
			else
			{
				printf("head is not null\n");
				head = ft_lstadd_to_head(dir, head);
			}
			printf("after head init\n");
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
	}
	closedir(sub_d);
	return (head);
}

void				read_into_dir(void)
{
	DIR				*d;
	struct dirent	*dir;
	t_filedata		*head;
	int i = 1;
	int j = 1;

	d = opendir(".");
	head = NULL;
	if (d)
	{
		while ((dir = readdir(d)) != NULL)
		{
			if (head == NULL)
			{
				printf("calls for a head == %i\n",i);
				i++;
				head = new_node(dir);
			}
			else
			{
				printf("calls for a head () == %i\n",j);
				j++;
				head = ft_lstadd_to_head(dir, head);
			}
			if (dir->d_type == 4)
			{
				if (ft_strncmp((char *)dir->d_name, ".", 1) != 0)
					head->sub = sub((char *)dir->d_name);
			}
		}
		closedir(d);
	}
}
