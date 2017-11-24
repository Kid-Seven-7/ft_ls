/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 09:48:21 by jngoma            #+#    #+#             */
/*   Updated: 2017/06/11 12:37:26 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char	temp[len];

	if (len >= (128 * 1024 * 1024))
		return (NULL);
	ft_memcpy(temp, src, len);
	ft_memcpy(dest, temp, len);
	return (dest);
}
