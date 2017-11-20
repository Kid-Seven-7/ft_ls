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

void    ft_lstsort(t_list *head)
{
  char      *temp;
  int       flag;

  flag = 1;
  if (head->next)
    while (flag != 0)
    {
      while(head->next)
      {
        if ((char*)head->content[0] > (char*)head->next->content[0])
        {
          temp = head->content;
          head->content = head->next->content;
          head->next->content = temp;
        }
        else
        head = head->next;
      }
    }
}

t_list	*ft_lstadd_to_head(t_list *list, char *str)
{
  t_list    *temp;

  temp = ft_lstnew(str, ft_strlen(str));
  if (temp)
    temp->next = list;
  return (temp);
}

int main(void)
{
  DIR             	*d;
  struct dirent   	*dir;
  t_list      			*head;
  int               i;

  head = NULL;
  dir = NULL;
  i = 0;
  d = opendir(".");
  if (d)
  {
    while ((dir = readdir(d)) != NULL)
      if (head == NULL)
        head = ft_lstnew((char *)dir->d_name, ft_strlen((char *)dir->d_name));
      else
        head = ft_lstadd_to_head(head, (char *)dir->d_name);
    closedir(d);
    // ft_lstsort(&head);
	  while (head != NULL)
    {
      i++;
      ft_putstr(head->content);
      if (ft_strlen((char *)head->content) > 7)
        ft_putstr("\t");
      else
        ft_putstr("\t\t");
      if (i % 9 == 0)
        ft_putstr("\n");
      head = head->next;
    }
  }
  else
  {

  }
  return (0);
}
