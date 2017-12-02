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
	t_filedata *prev;
	t_filedata *next;
	t_filedata *temp;

	temp = NULL;
	next = NULL;
	prev = NULL;
	printf("\n");
	while ((*cur))
	{
		if (prev && ((*cur)->next))
		{
			printf("prev is %s\n", prev->name);
			printf("cur is %s\n", (*cur)->name);
			printf("cur next is %s\n", (*cur)->next->name);
			if(ft_strcmp(((*cur)->name), (*cur)->next->name) > 0)
				printf("change\n");
		}
		prev = (*cur);
		(*cur) = (*cur)->next;
	}
}
