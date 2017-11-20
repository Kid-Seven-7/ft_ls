/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:06:00 by jngoma            #+#    #+#             */
/*   Updated: 2017/11/20 11:56:09 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

t_list	*ft_lstadd_to_head(t_list *list, char *str)
{
	t_list			*temp;

	temp = ft_lstnew(str, ft_strlen(str));
	if (temp)
		temp->next = list;
	return (temp);
}

void	read(void)
{
	DIR				*d;
	struct dirent	*dir;
	t_list			*head;

	d = opendir(".");
	if (d)
	{
		while ((dir = readdir(d)) != NULL)
			if (head == NULL)
				head = ft_lstnew((char *)dir->d_name,
						ft_strlen((char *)dir->d_name));
			else
				head = ft_lstadd_to_head(head, (char *)dir->d_name);
		closedir(d);
		while (head != NULL)
		{
			ft_putendl(head->content);
			head = head->next;
		}
	}
}
