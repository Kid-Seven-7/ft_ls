/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 07:30:46 by jngoma            #+#    #+#             */
/*   Updated: 2017/07/21 13:41:36 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*current;

	while (*alst)
	{
		current = *alst;
		*alst = (*alst)->next;
		del(current->content, current->content_size);
		free(current);
		current = NULL;
	}
}
