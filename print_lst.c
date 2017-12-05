/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 10:19:53 by jngoma            #+#    #+#             */
/*   Updated: 2017/12/04 15:46:33 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    print_lst(t_fdata *list, t_dir *data)
{
  int   i;

  i = -1;
  (void)list;
  if (data->params)
  {
    while (data->params[++i] != '\0')
    {
      if (data->params[i])
      {
        if (data->params[i] == 'R')
          printf("param is R\n");
        if (data->params[i] == 'l')
          printf("param is l\n");
        if (data->params[i] == 't')
          printf("param is t\n");
        if (data->params[i] == 'a')
          printf("param is a\n");
        if (data->params[i] == 'r')
          printf("param is r\n");
      }
    }
  }
}
