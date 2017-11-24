/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_2dchar.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 13:38:57 by jngoma            #+#    #+#             */
/*   Updated: 2017/07/21 13:47:20 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**ft_malloc_2dchar(int y, int x)
{
	char	**grid;
	int		i;

	grid = (char **)ft_memalloc(sizeof(grid) * y);
	i = 0;
	while (i < y)
	{
		grid[i] = (char *)ft_memalloc(sizeof(char) * x);
		i++;
	}
	return (grid);
}
