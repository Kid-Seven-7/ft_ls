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

int		arg_check(int ac, char **av)
{
	int	i;
	int	j;
	int	flag;
	t_filedata	*list;

	i = 0;
	j = -1;
	flag = 1;
	while (++i < ac)
	{
		printf("DEBUGGING\nav[%i] is %s\n\n",i, av[i]);
		if (av[i][0] == '-')
		{
			while (av[i][++j] != '\0')
			{
				if (av[i][j] != 'R' || av[i][j] != 'l' || av[i][j] != 'a') /*av[i][j] != '')av[i][j] != ''*/
					flag = 0;
				else
					flag = 1;
			}
		}
		else
		list = sub(av[i]);
		if (list)
		{
			detailed(list);
			flag = 0;
		}
		else
			flag = 1;

	}
	return (flag == 1) ? 0 : 1;
}
