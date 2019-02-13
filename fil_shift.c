#include "fillit.h"

void	fil_shift(char ***array) // сделать два шифта (горизонтальный и вертикальынй), оба вызывать в fil_valid
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((*array)[i])
	{
		j = 0;
		while ((*array)[i][j])
		{
			if ((*array)[i][j] == '#')
				break ;
			j++;
		}
		if (j == 4 && i == 0)
		{
			ft_memcpy((*array)[i], (*array)[i + 1], 4);
			ft_memcpy((*array)[i + 1], (*array)[i + 2], 4);
			ft_memcpy((*array)[i + 2], (*array)[i + 3], 4);
			ft_memcpy((*array)[i + 3], "....", 4);
			i = -1;
		}
		i++;
	}
	while (((*array)[0][0] == '.') && ((*array)[1][0] == '.')\
		&& ((*array)[2][0] == '.') && ((*array)[3][0] == '.'))
	{
		i = 0;
		while ((*array)[i])
		{
			j = 0;
			while ((*array)[i][j])
			{
				(*array)[i][j] = (*array)[i][j + 1];
				j++;
			}
			(*array)[i][3] = '.';
			i++;
		}
	}
}
// черновик