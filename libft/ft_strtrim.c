/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:00:14 by jngoma            #+#    #+#             */
/*   Updated: 2017/07/21 13:34:00 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	iswhitespace(char c)
{
	if (c == '\t' || c == '\n' || c == ' ')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	char	*newstr;

	if (!s)
		return (NULL);
	start = 0;
	end = ft_strlen(s);
	while (iswhitespace(s[start]))
		start++;
	while (iswhitespace(s[end - 1]))
		end--;
	newstr = ft_strnew((start > end) ? 0 : end - start);
	if (newstr == NULL)
		return (NULL);
	ft_strncpy(newstr, &s[start], (start > end) ? 0 : end - start);
	return (newstr);
}
