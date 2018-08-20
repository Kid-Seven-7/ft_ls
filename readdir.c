/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readdir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 09:23:40 by jngoma            #+#    #+#             */
/*   Updated: 2018/08/19 17:04:40 by jngoma           ###   ########.fr       */
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
		while ((dir = readdir(sub_d)))
		{
			joined = ft_strjoin(str, "/");
			joined = ft_strjoin(joined, (char*)dir->d_name);
			if (!head)
				head = new_node(dir, joined);
			else
				head = ft_lstadd_to_head(dir, head, joined);
			if (dir->d_type == 4)
				if (ft_strncmp((char *)dir->d_name, ".", 1) != 0)
					head->sub = sub(joined);
		}
	closedir(sub_d);
	while (head)
		head = head->next;
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
		while ((dir = readdir(d)))
		{
			if (!head)
				head = new_node(dir, dir->d_name);
			else
				ft_lstadd_to_head(dir, head, dir->d_name);
			if (dir->d_type == 4)
				if (!(ft_strnequ((char *)dir->d_name, "..", 2)))
					head->sub = sub((char *)dir->d_name);
		}
		closedir(d);
	}
	return (head);
}

char				*sort_of_name(char *target, char *d_name)
{
	char			name[256];
	char			temp[256];
	int				i;
	int				j;

	i = -1;
	j = -1;
	ft_bzero(temp, 256);
	while (++i < ft_strlen(target))
		temp[i] = target[i];
	i = -1;
	temp[ft_strlen(target)] = '/';
	ft_bzero(name, 256);
	while (++i < ft_strlen(temp))
	{
		name[i] = temp[i];
		if (i + 1 == ft_strlen(temp))
		{
			name[i + 1] = '/';
			while (++j < ft_strlen(d_name))
				name[j + (i + 1)] = d_name[j];
		}
	}
	return (ft_strdup(name));
}

t_fdata				*read_into_dir_tar(char *target)
{
	DIR				*d;
	struct dirent	*dir;
	t_fdata			*head;
	char			*name;

	d = opendir(target);
	head = NULL;
	if (d)
	{
		while ((dir = readdir(d)) != NULL)
		{
			name = sort_of_name(target, dir->d_name);
			if (!head)
				head = new_node(dir, name);
			else
				ft_lstadd_to_head(dir, head, name);
		}
		closedir(d);
	}
	return (head);
}
