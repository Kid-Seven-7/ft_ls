/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_fields.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:27:33 by jngoma            #+#    #+#             */
/*   Updated: 2017/12/04 15:28:06 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	swap_fileds(t_fdata **small, t_fdata **big, t_fdata **prev)
{
	t_fdata	*temp;
	t_fdata	*big_ptr;

	big_ptr = NULL;
	big_ptr = (*big)->next;
	temp = (*small);
	(*small) = (*big);
	(*big) = temp;
	(*small)->next = (*big);
	(*big)->next = big_ptr;
	if ((*prev) != NULL)
		(*prev)->next = (*small);
}
