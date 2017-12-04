/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 07:46:55 by jngoma            #+#    #+#             */
/*   Updated: 2017/07/21 13:35:01 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	if (s)
	{
		if (!(dst = (char*)malloc(sizeof(*dst) * (len + 1))))
			return (NULL);
		i = 0;
		while (i < len)
		{
			dst[i] = s[start + i];
			i++;
		}
		dst[i] = '\0';
		return (dst);
	}
	return (NULL);
}
