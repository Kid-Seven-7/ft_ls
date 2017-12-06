/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_to_head.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 12:07:56 by jngoma            #+#    #+#             */
/*   Updated: 2017/12/06 16:03:41 by jngoma           ###   ########.fr       */
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
		temp->next = new_node(dir);
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
