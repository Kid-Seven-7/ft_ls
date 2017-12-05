/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 09:44:47 by jngoma            #+#    #+#             */
/*   Updated: 2017/12/05 10:41:18 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		file_check(int ac, char **av, int i, t_dir **data)
{
	char *joined;
	t_dir	*temp;

	temp = (*data);
	while (i < ac)
	{
		joined = ft_strjoin("./", av[i]);
		temp->name = joined;
		i++;
		temp = temp->next;
	}
}

void		init_data(t_dir **data)
{
	(*data) = (t_dir *)malloc(sizeof(t_dir));
	(*data)->params = (char *)malloc(sizeof(char) * 5);
	ft_bzero((*data)->params, 5);
}

void		param_check(int ac, char **av, t_dir **data)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = -1;
	while (++i < ac)
	{
		j = 0;
		if (av[i][j] == '-')
			while (av[i][++j] != '\0')
				(*data)->params[++k] = av[i][j];
		else
			file_check(ac, av, i, data);
	}
}

void		arg_check(int ac, char **av)
{
	t_dir	*data;
	t_fdata	*list;

	list = NULL;
	init_data(&data);
	if (ac > 1)
		param_check(ac, av, &data);
	else
		data->name = ".";
	list = read_into_dir(data);
	// detailed(list);
	print_lst(list, data);
}
