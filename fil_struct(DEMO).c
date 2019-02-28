#include "fillit.h"

// DEMO
void	fil_print_one_struct(t_flist *list)
{
	int		i;

	i = 0;
	if (list)
	{
		while (i < 4)
		{
			ft_putnbr(list->x[i]);
			write(1, " ", 1);
			ft_putnbr(list->y[i]);
			write(1, "\n", 1);
			i++;
		}
	}
}



































/*// DEMO
void	fil_print_struct(t_flist *begin)
{
	int		i;
	t_flist	*temp;

	i = 0;
	if (begin)
	{
		temp = begin;
		while (temp)
		{
			i = 0;
			while ((temp->array)[i])
				ft_putendl((temp->array)[i++]);
			temp = temp->next;
			if (temp)
				ft_putstr("\n");
		}
	}
}*/

/*void	fil_print_one_struct1(t_flist *list)
{
	int		i;

	i = 0;
	if (list)
	{
		while ((list->array)[i])
			ft_putendl((list->array)[i++]);
	}
}*/
