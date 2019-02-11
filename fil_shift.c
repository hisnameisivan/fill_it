#include "fillit.h"

void	fil_shift(char ***array)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*(array[i]))
	{
		j = 0;
		while (*(array[i][j]))
		{
			if (*(array[i][j]) == '#')
				break ;
			j++;
		}
		if (j == 4)
		{
			ft_memcpy(*(array[i]), *(array[i + 1]), 4);
			ft_memcpy(*(array[i + 1]), *(array[i + 2]), 4);
			ft_memcpy(*(array[i + 2]), *(array[i + 3]), 4);
			ft_memcpy(*(array[i + 3]), "....", 4);
		}
		i++;
	}
}
// черновик