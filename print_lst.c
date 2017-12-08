/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 10:19:53 by jngoma            #+#    #+#             */
/*   Updated: 2017/12/06 16:13:50 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	process(t_fdata *list, t_dir *data)
{
	int 	l;
	int 	a;
	int 	i;

	l = 0;
	a = 0;
	i = -1;
	while (data->params[++i] != '\0')
	{
		if (data->params[i] == 'l')
			l = 1;
		if (data->params[i] == 'a')
			a = 1;
	}
	if (l == 1 && a == 0)
		detailed(list);
	else if (a == 1 && l == 0)
		print_hidden(list);
 	else if(a == 1 && l == 1)
		print_dhidden(list);
}

void	print_lst(t_fdata *list, t_dir *data)
{
	int		i;
	int		flag;

	i = -1;
	flag = 0;
	while (data->params[++i] != '\0')
	{
		if (data->params[i] == 'l' || data->params[i] == 'a')
		{
			if (flag == 0)
				process(list, data);
			flag++;
		}
		if (data->params[i] == 'R')
		{
			printf("param is R\n");
			flag++;
		}
	}
	if (flag == 0)
		default_print(list);
}

void	sort_lst(t_fdata *list, t_dir *data)
{
	int		i;

	i = -1;
	sort_by_name(&list);
	while (data->params[++i] != '\0')
	{
		if (data->params[i] == 't')
			sort_by_time(&list);
		if (data->params[i] == 'r')
			sort_by_name_rev(&list);
	}
	print_lst(list, data);
}
