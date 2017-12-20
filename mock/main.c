/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jngoma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 10:23:29 by jngoma            #+#    #+#             */
/*   Updated: 2017/12/20 11:11:42 by jngoma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <sys/stat.h>
#include <dirent.h>

typedef struct			s_files
{
	char				*file;
	struct s_files		*next;
}						t_files;

t_files					*new_file(char *name)
{
	t_files				*head;

	head = (t_files *)malloc(sizeof(t_files));
	head->file = ft_strdup(name);
	head->next = NULL;
	return (head);
}

t_files					*add_file(t_files *head, char *name)
{
	t_files				*trav;

	trav = head;
	while (trav->next)
		trav = trav->next;
	trav->next = (t_files*)malloc(sizeof(t_files));
	trav->next->file = ft_strdup(name);
	trav->next->next = NULL;
	return (trav);
}

t_files					*alloc_files(t_files *head, char *name)
{
	t_files				*trav;

	trav = head;
	if (trav == NULL)
	{
		trav = new_file(name);
		head = trav;
	}
	else
	{
		trav = add_file(head, name);
		trav = head;
	}
	return (trav);
}


char		*options(char *str, char *s2)
{
	char	*temp;
	char	*file;

	temp = ft_strjoin(s2, str);
	free(s2);
	return (temp);
}

void			print_files(t_files *head)
{
	t_files		*trav;

	trav = head;
	while (trav)
	{
		ft_putendl(trav->file);
		trav = trav->next;
	}
}

void		ft_ls_files(t_files *direct, char *options)
{
	t_files	*trav;

	trav = direct;
	while (trav)
	{
		ft_ls(trav->file, options);
		trav = trav->next;
	}
}


void		ft_ls_target(t_files *head, char *options)
{
	t_files	*trav;
	struct stat			info;
	struct dirent		*dp;
	DIR					*folder;
	t_files				*directory;

	directory = NULL;
	trav = head;
	while (trav)
	{
		if ((dp = opendir(trav->file)))
			directory = alloc_files(directory, dp->d_name);
		else
			ft_ls(trav->file, options);
	}
	if (directory)
		ft_ls_files(directory, options);
}

int			main(int argc, char **argv)
{
	int		i;
	int		flag;
	char	*opts;
	t_files	*head;

	flag = 0;
	head = NULL;
	opts = ft_strnew(1);
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && !head)
		{
			if (!&argv[i][1])
				ft_putstr("ft_ls '-' : No such file or directory\n");
			else
				opts = options(&argv[i][1], opts);
		}
		else if (ft_isalnum(argv[i][0]))
		{
			flag = 1;
			head = alloc_files(head, argv[i]);
		}
		i++;
	}
	if (flag == 0)
		ft_ls(".", options);
	else
		ft_ls_files(head, options);
}
