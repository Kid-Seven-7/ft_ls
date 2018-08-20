/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 10:56:53 by jngoma            #+#    #+#             */
/*   Updated: 2018/08/19 16:54:35 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_rec					*new_file(char *line)
{
	t_rec			*head;

	head = (t_rec *)malloc(sizeof(t_rec));
	head->file = ft_strdup(line);
	head->next = NULL;
	return (head);
}

t_rec					*add_file(t_rec *head, char *line)
{
	t_rec			*trav;

	trav = head;
	while (trav->next)
		trav = trav->next;
	trav->next = (t_rec*)malloc(sizeof(t_rec));
	trav->next->file = ft_strdup(line);
	trav->next->next = NULL;
	return (trav);
}

t_rec					*dynamic(t_rec *head, char *line)
{
	t_rec			*trav;

	trav = head;
	if (trav == NULL)
	{
		trav = new_file(line);
		head = trav;
	}
	else
	{
		trav = add_file(head, line);
		trav = head;
	}
	return (trav);
}

void					loop(t_rec *head, int format)
{
	t_rec			*trav;

	trav = head;
	while (trav)
	{
		recursion(trav->file, format);
		trav = trav->next;
	}
}

void					recursion(char *target, int format)
{
	struct dirent	*dir;
	DIR				*dp;
	t_rec			*head;
	char			*name;
	char			*one;

	if (format == 1)
		detailed(read_into_dir_tar(target));
	head = NULL;
	if (!(dp = opendir(target)))
		return ;
	name = ft_strjoin(target, "/");
	while ((dir = readdir(dp)))
	{
		if (format == 0)
			ft_putendl(dir->d_name);
		if (ft_strcmp(dir->d_name, ".") == 0 ||
		ft_strcmp(dir->d_name, "..") == 0)
			;
		else if (dir->d_type == DT_DIR)
			head = dynamic(head, ft_strjoin(name, dir->d_name));
	}
	if (head)
		loop(head, format);
}
