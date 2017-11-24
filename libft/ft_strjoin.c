/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 07:45:04 by jngoma            #+#    #+#             */
/*   Updated: 2017/07/21 13:37:30 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		i;
	int		j;

	if (s1 && s2)
	{
		dst = (char*)malloc(sizeof(*dst) * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (!dst)
			return (NULL);
		i = 0;
		j = -1;
		while (s1[++j])
			dst[i++] = s1[j];
		j = -1;
		while (s2[++j])
			dst[i++] = s2[j];
		dst[i] = '\0';
		return (dst);
	}
	return (NULL);
}
