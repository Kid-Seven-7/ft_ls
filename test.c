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

t_list	*ft_lstadd_to_head(t_list *list, char *str)
{
  t_list    *temp;

  temp = malloc(sizeof(t_list));
  if (temp)
  {
    temp->content = str;
    temp->next = list;
  }
  return (temp);
}

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
      head = ft_lstadd_to_head(head, (char *)dir->d_name);
    }
    closedir(d);
	  while (head)
    {
         printf("head is %s\n", head->content);
        head = head->next;
    }
  }
  return (0);
}
