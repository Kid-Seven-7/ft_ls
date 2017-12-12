/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 14:14:26 by jngoma            #+#    #+#             */
/*   Updated: 2017/12/12 14:16:12 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	valid_parmas(char *params, int i)
{
	while (params[++i])
	{
		if (params[i] == 'R')
			valid_parmas(params, i);
		else if (params[i] == 'a')
			valid_parmas(params, i);
		else if (params[i] == 'l')
			valid_parmas(params, i);
		else if (params[i] == 'r')
			valid_parmas(params, i);
		else if (params[i] == 't')
			valid_parmas(params, i);
		else
		{
			ft_putstr("ls: illegal option -- ");
			ft_putchar(params[i]);
			ft_putstr("\nusage: ls [-Ralrt] [file ...]\n");
			exit(1);
		}
	}
}

int		print_error(char *file)
{
	ft_putstr("ls: ");
	ft_putstr(file);
	ft_putendl(": No such file or directory");
	return (1);
}
