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
