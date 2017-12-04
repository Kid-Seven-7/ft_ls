/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:30:34 by jngoma            #+#    #+#             */
/*   Updated: 2017/12/04 15:31:57 by jngoma           ###   ########.fr       */
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

typedef struct		s_ls
{
	char				*params;
	char				*file;
	struct s_filedata	*data;
}					t_ls;

typedef struct		s_filedata
{
	char				*name;
	char				*timestamp;
	char				*uid;
	char				*gid;
	long int			size;
	long int			block;
	unsigned long int	links;
	char				*permissions;
	struct s_filedata	*sub;
	struct s_filedata	*next;
}					t_fdata;

void				arg_check(int ac, char **av);
void				read_into_dir(char *file);
void				detailed(t_fdata *list);
void				sort_by_name(t_fdata **cur);
void				swap_fileds(t_fdata **small, t_fdata **big, t_fdata **prev);
t_fdata				*sub(char *str);
t_fdata				*new_node(struct dirent *dir);
t_fdata				*ft_lstsub_to_head(struct dirent *dir, t_fdata *list);
t_fdata				*ft_lstadd_to_head(struct dirent *dir, t_fdata *list);

#endif
