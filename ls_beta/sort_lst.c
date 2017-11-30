/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 10:09:00 by jngoma            #+#    #+#             */
/*   Updated: 2017/11/30 10:34:47 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_by_name(t_filedata **cur)
{
	int		flag;
	t_filedata	*next;
	t_filedata	*prev;

	flag = 1;
	while (flag < 0)
	{
		while (cur)
		{
			next = (*cur)->next;
			if ((*cur)->next->name[0] > (*cur)->name[0])
			{
				(*cur)->next = next->next;
				prev->next = next;
				next->next = *cur;
				flag++;
			}
			prev = *cur;
			cur = &next;
			if (flag == 1)
				flag = 0;
		}
	}
}
