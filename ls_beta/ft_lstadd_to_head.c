/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_to_head.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 12:07:56 by jngoma            #+#    #+#             */
/*   Updated: 2017/11/29 10:36:33 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_filedata	*ft_lstadd_to_head(struct dirent *dir, t_filedata *list)
{
	t_filedata	*temp;

	temp = list;
	while(temp->next)
	{
		temp = temp->next;
	}
	if (temp)
	{
		temp->next = new_node(dir);
	}
	return (temp);
	//
	// temp = new_node(dir);
	// if (temp)
	// 	temp->next = list;
	// return (temp);
}

t_filedata	*ft_lstsub_to_head(struct dirent *dir, t_filedata *list)
{
	t_filedata	*temp;

	temp = new_node(dir);
	if (temp)
		temp->sub->next = list;
	return (temp);
}
