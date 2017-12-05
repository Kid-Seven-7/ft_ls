#include "ft_ls.h"

void		total_blocks(t_fdata *list)
{
	int		total;

	total = 0;
	while (list)
	{
		total += list->block;
		list = list->next;
	}
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putstr("\n");
}

void		detailed(t_fdata *list)
{
	total_blocks(list);
	while (list)
	{
		if (list->name[0] != '.')
		{
			ft_putstr(list->permissions);
			ft_putstr("\t");
			ft_putnbr(list->links);
			ft_putstr(" ");
			ft_putstr(list->uid);
			ft_putstr(" ");
			ft_putstr(list->gid);
			ft_putstr("\t");
			ft_putnbr(list->size);
			ft_putstr("\t");
			ft_putstr(list->timestamp);
			ft_putstr(" ");
			ft_putstr(list->name);
			ft_putstr("\n");
			list = list->next;
		}
		else
			list = list->next;
	}
}
