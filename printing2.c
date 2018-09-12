/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 18:49:11 by jngoma            #+#    #+#             */
/*   Updated: 2018/09/11 18:49:18 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void readable(long int size)
{
	float new_size = size;
	float test = 0;
	char c[50]; //size of the number
	char d[50]; //size of the number

	// float f = 1.123456789;

	test = new_size / 1024.0f;
	sprintf(c, "%.2g", test);
	sprintf(d, "%g", new_size);
	if (test > 1){
		ft_putstr(c);
		ft_putstr("K\t");
	}
	else{
		ft_putstr(d);
		ft_putstr("B\t");
	}

}

void		print_dkhidden(t_fdata *list)
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
		// ft_putnbr(list->size);
		// ft_putstr("\t");
		readable(list->size);
		ft_putstr(list->timestamp);
		ft_putstr(" ");
		ft_putstr(list->name);
		ft_putstr("\n");
		list = list->next;
	}
	ft_putstr("\n");
}
