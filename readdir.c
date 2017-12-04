/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readdir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 09:23:40 by jngoma            #+#    #+#             */
/*   Updated: 2017/12/04 15:21:16 by jngoma           ###   ########.fr       */
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
	if (sub_d)
		while ((dir = readdir(sub_d)) != NULL)
		{
			if (head == NULL)
				head = new_node(dir);
			else
				head = ft_lstadd_to_head(dir, head);
			if (dir->d_type == 4)
				if (ft_strncmp((char *)dir->d_name, ".", 1) != 0)
				{
					joined = ft_strjoin(str, "/");
					joined = ft_strjoin(joined, (char*)dir->d_name);
					sub(joined);
				}
		}
	closedir(sub_d);
	return (head);
}

void				read_into_dir(char *file)
{
	DIR				*d;
	struct dirent	*dir;
	t_fdata			*head;

	d = opendir(file);
	head = NULL;
	if (d)
	{
		while ((dir = readdir(d)) != NULL)
		{
			if (head == NULL)
				head = new_node(dir);
			else
				ft_lstadd_to_head(dir, head);
			if (dir->d_type == 4)
			{
				if (!(ft_strnequ((char *)dir->d_name, "..", 2)))
					head->sub = sub((char *)dir->d_name);
			}
		}
		closedir(d);
	}
	sort_by_name(&head);
	detailed(head);
}
