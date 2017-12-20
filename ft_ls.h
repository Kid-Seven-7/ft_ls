/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:30:34 by jngoma            #+#    #+#             */
/*   Updated: 2017/12/12 14:00:29 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <sys/stat.h>
# include <sys/types.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>

typedef	struct		s_dir
{
	char					*params;
	char					*name;
	struct s_dir			*next;
}					t_dir;

typedef struct		s_ls
{
	char					*params;
	char					*file;
}					t_ls;

typedef struct		s_fdata
{
	char					*name;
	char					*timestamp;
	long					time;
	char					*uid;
	char					*gid;
	unsigned int	g_id;
	long int				size;
	long int				block;
	unsigned long int		links;
	char					*permissions;
	struct s_fdata			*sub;
	struct s_fdata			*next;
}					t_fdata;

void				detailed(t_fdata *list);
void  				valid_parmas(char *params, int i);
void				sort_by_name(t_fdata **cur);
void				sort_by_time(t_fdata **cur);
void				arg_check(int ac, char **av);
void				default_print(t_fdata *list);
void				print_hidden(t_fdata *list);
void				print_dhidden(t_fdata *list);
void				sort_by_name_rev(t_fdata **list);
void				process(t_fdata *list, t_dir *data);
void				sort_lst(t_fdata *list, t_dir *data);
void				print_lst(t_fdata *list, t_dir *data);
void				add_to_params(char *params, char param);
void				swap_fileds(t_fdata **small, t_fdata **big, t_fdata **prev);
char				*my_time(struct stat stats);
int				print_error(char *file);
void				recursion(char *target);

t_fdata				*sub(char *str);
t_fdata				*read_into_dir(t_dir *data);
t_fdata				*new_node(struct dirent *dir, char *file);
t_fdata				*ft_lstsub_to_head(struct dirent *dir, t_fdata *list, char *file);
t_fdata				*ft_lstadd_to_head(struct dirent *dir, t_fdata *list, char *file);

#endif
