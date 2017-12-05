/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_to_head.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 12:07:56 by jngoma            #+#    #+#             */
/*   Updated: 2017/12/04 15:32:46 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_fdata	*ft_lstadd_to_head(struct dirent *dir, t_fdata *list)
{
	t_fdata	*temp;

	temp = list;
	while (temp->next)
	{
		temp = temp->next;
	}
	if (temp)
	{
		// printf("\nin ft_lstadd_to_head dir name is %s\n", dir->d_name);
		temp->next = new_node(dir);
		// printf("\nin ft_lstadd_to_head temp->next name is %s\n", temp->next->name);
}
	return (temp);
}

t_fdata	*ft_lstsub_to_head(struct dirent *dir, t_fdata *list)
{
	t_fdata	*temp;

	temp = new_node(dir);
	if (temp)
		temp->sub->next = list;
	return (temp);
}
