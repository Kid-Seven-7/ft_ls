/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:13:59 by jngoma            #+#    #+#             */
/*   Updated: 2017/12/12 16:47:51 by jngoma           ###   ########.fr       */
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

void		print_hidden(t_fdata *list)
{
	while (list)
	{
		ft_putstr(list->name);
		ft_putstr("\t");
		list = list->next;
	}
	ft_putstr("\n");
}

void		print_dhidden(t_fdata *list)
{
	total_blocks(list);
	while (list)
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
	ft_putstr("\n");
}

void		default_print(t_fdata *list)
{
	while (list)
	{
		if (list->name[0] != '.')
		{
			ft_putstr(list->name);
			ft_putstr("\t");
			list = list->next;
		}
		else
			list = list->next;
	}
	ft_putstr("\n");
}

void		detailed(t_fdata *list)
{
	total_blocks(list);
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
