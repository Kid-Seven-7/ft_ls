/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:56:38 by jngoma            #+#    #+#             */
/*   Updated: 2017/11/20 13:19:18 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int main(int ac, char **av)
{
	if (ac > 1)
	{
		printf("%i\n", arg_check(ac, av));
		if (arg_check(ac, av) == 0)
			read_into_dir();
		else
			ft_putendl("invalid");
	}
	else
	read_into_dir();
	return (0);
}
