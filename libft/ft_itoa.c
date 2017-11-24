/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 07:40:21 by jngoma            #+#    #+#             */
/*   Updated: 2017/11/13 09:49:31 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*sval;
	long	lval;
	int		sign;
	int		i;

	if (n == -2147483648)
		return ("-2147483648");
	lval = (n < 0) ? -(long)n : n;
	sign = (n < 0) ? -1 : 1;
	i = (sign == -1) ? 2 : 1;
	while ((lval /= 10) > 0)
		i++;
	sval = (char *)malloc(i);
	sval[i] = '\0';
	lval = (n < 0) ? -(long)n : n;
	while (i-- + sign)
	{
		sval[i] = (lval % 10 < 10) ? lval % 10 + '0' : 0;
		lval /= 10;
	}
	(i == 0) ? sval[i] = '-' : 0;
	return (sval);
}
