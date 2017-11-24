/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/25 07:40:31 by jngoma            #+#    #+#             */
/*   Updated: 2017/06/25 07:40:33 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *mem;

	if (!(mem = (void*)malloc(sizeof(*mem) * (size))) || !size)
		return (NULL);
	mem = ft_memset(mem, 0, size);
	return (mem);
}
