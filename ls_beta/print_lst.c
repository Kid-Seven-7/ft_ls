/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 10:19:53 by jngoma            #+#    #+#             */
/*   Updated: 2017/11/30 13:34:33 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		detailed(t_filedata *list)
{
	while (list->next)
	{
		//if (ft_strcmp(list->name, ".") || ft_strcmp(list->name, "..")
			//list = list->next;
		if (list->name[0] != '.')
		{
			ft_putstr(list->permissions);
			ft_putstr("\t");
			//ft_putnbr(list->links);
			//ft_putstr(" ");
			//ft_putstr(list->uid);
			//ft_putstr(" ");
			//ft_putstr(list->gid);
			//ft_putstr("\t");
			//ft_putnbr(list->size);
			//ft_putstr("\t");
			//ft_putstr(list->timestamp);
			//ft_putstr(" ");
			ft_putstr(list->name);
			ft_putstr("\n");
		}
		list = list->next;
	}
}
