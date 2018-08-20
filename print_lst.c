/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 10:19:53 by jngoma            #+#    #+#             */
/*   Updated: 2018/08/19 17:17:39 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	process(t_fdata *list, t_dir *data)
{
	int		l;
	int		a;
	int		i;
	int		r;

	l = 0;
	a = 0;
	r = 0;
	i = -1;
	while (data->params[++i] != '\0')
	{
		l += (data->params[i] == 'l') ? 1 : 0;
		a += (data->params[i] == 'a') ? 1 : 0;
		r += (data->params[i] == 'R') ? 1 : 0;
	}
	if (r == 1)
		recursion(data->name, l);
	else if (l == 1 && a == 0)
		detailed(list);
	else if (a == 1 && l == 0)
		print_hidden(list);
	else if (a == 1 && l == 1)
		print_dhidden(list);
}

void	print_lst(t_fdata *list, t_dir *data)
{
	int		i;
	int		param;
	int		flag;

	i = -1;
	flag = 0;
	param = 0;
	while (data->params[++i] != '\0')
	{
		param += (data->params[i] == 'R') ? 1 : 0;
		param += (data->params[i] == 'a') ? 1 : 0;
		param += (data->params[i] == 'l') ? 1 : 0;
	}
	if (param == 0)
		default_print(list);
	else
		process(list, data);
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
		if (data->params[i] == 'S')
			sort_by_size(&list);
	}
	print_lst(list, data);
}
