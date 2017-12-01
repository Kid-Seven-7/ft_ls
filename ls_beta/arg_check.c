/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 09:44:47 by jngoma            #+#    #+#             */
/*   Updated: 2017/11/30 13:27:26 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		arg_check(int ac, char **av)
{
	if (ac > 1)
	{
		int			i;
		int			j;
		int			k;
		t_ls		*data;

		i = -1;
		k = -1;
		data = NULL;
		data->params = (char *)malloc(5);
		while (++i < ac)
		{
			j = -1;
			if (av[i][++j] == '-')
			{
				while (av[i][j] != '\0')
					data->params[++k] = av[i][j];
			}
			else
			{
				data->file = (char *)malloc(ft_strlen(av[i]));
				data->file = av[i];
			}
		}
	}
}
