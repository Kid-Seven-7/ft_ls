/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 11:31:35 by jngoma            #+#    #+#             */
/*   Updated: 2017/11/22 11:41:02 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_filedata	*init(void)
{
	t_filedata	*list;

	list = NULL;
	if (!(list = (t_filedata *)malloc(sizeof(t_filedata))))
		return (NULL);
	list->name = NULL;
	list->timestamp = NULL;
	list->uid = NULL;
	list->gid = NULL;
	list->size = 0;
	list->links = 0;
	list->permissions = 0;
	list->sub = NULL;
	list->next = NULL;
	return (list);
}
