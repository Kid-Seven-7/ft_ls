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

void 		file_check(int ac, char **av, int i)
{
	char *joined;

	while (i < ac)
	{
		joined = ft_strjoin("./", av[i]);
		read_into_dir(joined);
		printf("joined is %s\n", joined);
		i++;
	}
}

void		init_data(t_ls **data)
{
		(*data) = (t_ls *)malloc(sizeof(t_ls));
		(*data)->params = (char *)malloc(sizeof(char) * 5);
		(*data)->params[5] = '\0';
}

void 		param_check(int ac, char **av)
{
	t_ls		*data;
	int		i;
	int		j;
	int		k;

	init_data(&data);
	i = 0;
	k = -1;
	while (++i < ac)
	{
		j = 0;
		if (av[i][j] == '-')
			while (av[i][++j] != '\0')
				data->params[++k] = av[i][j];
		else
			file_check(ac, av, i);
	}
}

void		arg_check(int ac, char **av)
{
	if (ac > 1)
		param_check(ac, av);
	else
		read_into_dir(".");
}
