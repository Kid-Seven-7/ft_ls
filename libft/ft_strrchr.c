/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 07:46:23 by jngoma            #+#    #+#             */
/*   Updated: 2017/06/25 07:46:25 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*t;

	i = 0;
	t = NULL;
	while (s[i])
	{
		if (s[i] == c)
			t = s + i;
		i++;
	}
	if (s[i] == c)
		return ((char*)(s + i));
	return ((char*)t);
}
