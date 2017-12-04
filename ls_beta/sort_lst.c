/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 10:09:00 by jngoma            #+#    #+#             */
/*   Updated: 2017/12/04 10:26:19 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_by_name(t_filedata **list)
{
	t_filedata *cur;
	t_filedata *prev;

	cur = (*list);
	while (cur)
	{
		prev = cur;
		cur = cur->next;
		printf("prev %s\n", prev->name);
		printf("cur %s\n", cur->name);
	}
}
