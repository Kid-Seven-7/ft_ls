/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 18:15:31 by jngoma            #+#    #+#             */
/*   Updated: 2017/06/09 12:44:46 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = (char *)malloc(sizeof(char) * ft_strlen((char *)s1) + 1);
	if (new_str != NULL)
	{
		while (s1[i] != '\0')
		{
			new_str[i] = s1[i];
			i++;
		}
		new_str[i] = '\0';
		return (&(*new_str));
	}
	return (NULL);
}
