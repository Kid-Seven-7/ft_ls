/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:06:00 by jngoma            #+#    #+#             */
/*   Updated: 2017/11/21 14:11:44 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
				if (ft_strncmp((char *)dir->d_name, ".", 1) != 0)
					sub((char *)dir->d_name);
				else
					printf("%s\n", dir->d_name);
			}
			else
				printf("%s\n", dir->d_name);
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
