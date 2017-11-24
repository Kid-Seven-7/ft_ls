/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_2dint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 13:38:51 by jngoma            #+#    #+#             */
/*   Updated: 2017/07/21 13:47:31 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**ft_malloc_2dchar(int y, int x)
{
	int		**grid;
	int		i;

	grid = (int **)ft_memalloc(sizeof(grid) * y);
	i = 0;
	while (i < y)
	{
		grid[i] = (int *)ft_memalloc(sizeof(int) * x);
		i++;
	}
	return (grid);
}
