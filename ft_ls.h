/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 11:59:20 by jngoma            #+#    #+#             */
/*   Updated: 2017/11/22 11:59:26 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../libft/libft.h"
# include <sys/stat.h>
# include <sys/types.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>

typedef struct			s_filedata
{
	char				*name;
	char				*timestamp;
	char				*uid;
	char				*gid;
	long int			size;
	unsigned long int	links;
	unsigned int		permissions;
	struct	s_filedata	*sub;
	struct	s_filedata	*next;
}						t_filedata;

t_filedata			*init(void);
t_filedata			*new_node(struct dirent *dir);
void				read_into_dir(void);
int 				arg_check(int ac, char **av);
t_list				*ft_lstadd_to_head(t_list *list, char *str);

#endif
