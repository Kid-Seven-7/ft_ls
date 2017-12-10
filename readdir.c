/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readdir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 09:23:40 by jngoma            #+#    #+#             */
/*   Updated: 2017/12/05 10:36:49 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_fdata				*sub(char *str)
{
	DIR				*sub_d;
	struct dirent	*dir;
	t_fdata			*head;
	char			*joined;

	sub_d = opendir(str);
	head = NULL;
	printf("str is %s\n", str);
	if (sub_d)
		while ((dir = readdir(sub_d)) != NULL)
		{
			if (head == NULL)
				head = new_node(dir, joined);
			else
				head = ft_lstadd_to_head(dir, head, joined);
			printf("read: dir->name %s\n", dir->d_name);
			if (dir->d_type == 4)
				if (ft_strncmp((char *)dir->d_name, ".", 1) != 0)
				{
					joined = ft_strjoin(str, "/");
					joined = ft_strjoin(joined, (char*)dir->d_name);
					printf("joined is %s\n", joined);
					sub(joined);
				}
		}
	closedir(sub_d);
	return (head);
}

t_fdata				*read_into_dir(t_dir *data)
{
	DIR				*d;
	struct dirent	*dir;
	t_fdata			*head;

	d = opendir(data->name);
	head = NULL;
	if (d)
	{
		while ((dir = readdir(d)) != NULL)
		{
			if (head == NULL)
			{
				head = new_node(dir, "./");
			}
			else
			{
				ft_lstadd_to_head(dir, head, "./");
			}
			if (dir->d_type == 4)
			{
				if (!(ft_strnequ((char *)dir->d_name, "..", 2)))
					head->sub = sub((char *)dir->d_name);
			}
		}
		closedir(d);
	}
	return (head);
}
