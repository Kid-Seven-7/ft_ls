/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 10:19:53 by jngoma            #+#    #+#             */
/*   Updated: 2017/12/04 15:27:16 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		total_blocks(t_fdata *list)
{
	int		total;

	total = 0;
	while (list)
	{
		total += list->block;
		list = list->next;
	}
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putstr("\n");
}

void		detailed(t_fdata *list)
{
	while (list)
	{
		if (list->name[0] != '.')
		{
			ft_putstr(list->permissions);
			ft_putstr("\t");
			ft_putnbr(list->links);
			ft_putstr(" ");
			ft_putstr(list->uid);
			ft_putstr(" ");
			ft_putstr(list->gid);
			ft_putstr("\t");
			ft_putnbr(list->size);
			ft_putstr("\t");
			ft_putstr(list->timestamp);
			ft_putstr(" ");
			ft_putstr(list->name);
			ft_putstr("\n");
			list = list->next;
		}
		else
			list = list->next;
	}
}
