/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_to_head.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 12:07:56 by jngoma            #+#    #+#             */
/*   Updated: 2017/11/20 12:10:01 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_list	*ft_lstadd_to_head(t_list *list, char *str)
{
	t_list	*temp;

	temp = ft_lstnew(str, ft_strlen(str));
	if (temp)
		temp->next = list;
	return (temp);
}
