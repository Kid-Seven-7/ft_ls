/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 07:45:26 by jngoma            #+#    #+#             */
/*   Updated: 2017/07/21 13:36:03 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	int		i;

	if (f && s)
	{
		if (!(new = (char*)malloc(sizeof(*new) * (ft_strlen(s) + 1))))
			return (NULL);
		i = -1;
		while (s[++i])
			new[i] = f(s[i]);
		new[i] = '\0';
		return (new);
	}
	return (NULL);
}
