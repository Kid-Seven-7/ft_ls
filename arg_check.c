/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 09:44:47 by jngoma            #+#    #+#             */
/*   Updated: 2017/12/06 16:03:12 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		file_check(int ac, char **av, int i, t_dir **data)
{
	char	*joined;
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

void		add_to_params(char *params, char param)
{
	int		i;
	int		exists;

	exists = 1;
	i = -1;
	while (params[++i] != '\0')
	{
		if (param == params[i])
			exists = 0;
	}
	if (params[i] == '\0' && exists == 1)
		params[i] = param;
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
				add_to_params((*data)->params, av[i][j]);
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
	{
		data->name = ".";
		param_check(ac, av, &data);
	}
	else
		data->name = ".";
	list = read_into_dir(data);
	if (ac > 1)
		sort_lst(list, data);
	else
	{
		sort_by_name(&list);
		default_print(list);
	}
}
