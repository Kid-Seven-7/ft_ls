/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_to_head.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 12:07:56 by jngoma            #+#    #+#             */
/*   Updated: 2017/11/22 11:45:26 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_filedata	*ft_lstadd_to_head(struct dirent *dir, t_filedata *list)
{
	t_filedata	*temp;

	temp = new_node(dir);
	if (temp)
		temp->next = list;
	return (temp);
}
