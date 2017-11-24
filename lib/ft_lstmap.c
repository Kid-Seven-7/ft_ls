/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 11:31:08 by jngoma            #+#    #+#             */
/*   Updated: 2017/07/21 13:48:33 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*temp;
	t_list	*new_lst;

	new_lst = NULL;
	new_lst = f(lst);
	lst = lst->next;
	new_lst->next = NULL;
	temp = new_lst;
	while (lst)
	{
		temp->next = f(lst);
		lst = lst->next;
		temp = temp->next;
	}
	temp = NULL;
	return (new_lst);
}
