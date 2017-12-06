/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 10:09:00 by jngoma            #+#    #+#             */
/*   Updated: 2017/12/04 15:21:54 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_by_name(t_fdata **list)
{
	t_fdata *cur;
	t_fdata *prev;

	cur = (*list);
	prev = NULL;
	while (cur)
	{
		if (cur->next)
			if (ft_strcmp(cur->name, cur->next->name) > 0)
			{
				swap_fileds(&cur, &cur->next, &prev);
				cur = (*list);
			}
		prev = cur;
		cur = cur->next;
	}
}

void	sort_by_time(t_fdata **list)
{
	t_fdata *cur;
	t_fdata *prev;

	cur = (*list);
	prev = NULL;
	while (cur)
	{
		if (cur->next)
			if ((cur->time) < (cur->next->time))
			{
				swap_fileds(&cur, &cur->next, &prev);
				cur = (*list);
			}
		prev = cur;
		cur = cur->next;
	}
}

void	sort_by_name_rev(t_fdata **list)
{
	t_fdata *cur;
	t_fdata *prev;

	cur = (*list);
	prev = NULL;
	while (cur)
	{
		if (cur->next)
			if (ft_strcmp(cur->name, cur->next->name) < 0)
			{
				swap_fileds(&cur, &cur->next, &prev);
				cur = (*list);
			}
		prev = cur;
		cur = cur->next;
	}
}
