/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 09:44:47 by jngoma            #+#    #+#             */
/*   Updated: 2017/12/07 23:40:32 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		init_data(t_dir **data)
{
	(*data) = (t_dir *)malloc(sizeof(t_dir));
	(*data)->params = (char *)malloc(sizeof(char) * 5);
	(*data)->next = NULL;
	ft_bzero((*data)->params, 5);
}

int		file_check(int ac, char **av, int i, t_dir **data)
{
	char	*joined;
	t_dir	*temp;
	t_dir	*next;
	DIR		*d;

	temp = (*data);
	next = temp->next;
	while (i < ac)
	{
		joined = ft_strjoin("./", av[i]);
		d = opendir(joined);
		if (d)
		{
		temp->name = joined;
		temp = next;
		closedir(d);
		}
		else
		{
			ft_putstr("ls: ");
			ft_putstr(av[i]);
			ft_putstr(": No such file or directory\n");
			return (1);
		}
		i++;
	}
	return (0);
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
		if (av[i][j] == '-' && (ft_strlen(av[i]) > 1))
		{
			while (av[i][++j] != '\0')
				add_to_params((*data)->params, av[i][j]);
		}
		else
			k = file_check(ac, av, i, data);
	}
	if (k == 1)
		exit(1);
	valid_parmas((*data)->params, -1);
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
