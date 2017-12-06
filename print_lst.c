/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 10:19:53 by jngoma            #+#    #+#             */
/*   Updated: 2017/12/06 16:12:49 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_lst(t_fdata *list, t_dir *data)
{
	int		i;
	int		flag;

	i = -1;
	flag = 0;
	while (data->params[++i] != '\0')
	{
		if (data->params[i])
		{
			if (data->params[i] == 'R')
			{
				printf("param is R\n");
				flag++;
			}
			if (data->params[i] == 'l')
			{
				detailed(list);
				flag++;
			}
			if (data->params[i] == 'a')
			{
				print_hidden(list);
				flag++;
			}
			if (data->params[i] == 'a' && data->params[i + 1] == 'l')
			{
				print_dhidden(list);
				flag++;
			}
		}
	}
	if (flag == 0)
		default_print(list);
}

void	sort_lst(t_fdata *list, t_dir *data)
{
	int		i;

	i = -1;
	while (data->params[++i] != '\0')
	{
		if (data->params[i] != '\0')
		{
			if (data->params[i] == 't')
				sort_by_time(&list);
			if (data->params[i] == 'r')
				sort_by_name_rev(&list);
		}
	}
	if (i == 0)
		sort_by_name(&list);
	print_lst(list, data);
}
