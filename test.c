/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:06:00 by jngoma            #+#    #+#             */
/*   Updated: 2017/11/13 11:14:12 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int main(void)
{
  DIR             	*d;
  struct dirent   	*dir;
  t_list			*head;
  t_list			*temp;

  head = NULL;
  temp = NULL;
  head = (t_list*)malloc(sizeof(t_list));
  temp = (t_list*)malloc(sizeof(t_list));
  d = opendir(".");
  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    {
		temp->content = dir->d_name;
		ft_lstadd(&head, temp);
		ft_putendl(temp->content);
    }
    closedir(d);
	printf("head cont is %s\n", head->content);
	printf("temp cont is %s", head->content);
  }
  return (0);
}
