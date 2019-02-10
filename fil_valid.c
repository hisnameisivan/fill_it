#include "fillit.h"

int		fil_valid(int lns_num, char *line)
{
	int		i;
	int		j;
	int		sim_count;
	char	**spl_line;

	i = 0;
	j = 0;
	sim_count = 0;
	spl_line = ft_strsplit(line, '\n');
	while (spl_line[i])
	{
		if (ft_strlen(spl_line[i]) == 4)
			i++;
		else
			return (-1);
	}
	i = 0;
	while (spl_line[i])
	{
		j = 0;
		while (spl_line[i][j])
		{
			if (spl_line[i][j] == '#')
			{
				sim_count++;
				j++;
			}
			else if (spl_line[i][j] == '.')
				j++;
			else
				return (-1);
			if (j == 3 && (i + 1) % 4 == 0) // кратность четырем (одна поданная тетраминка). + 1 т.к. нумерация с нуля
			{
				if (sim_count != 4)
					return (-1);
				else
					sim_count = 0;
			}
		}
		i++;
	}
	if (lns_num != (i * 5 / 4 - 1)) // количество без \n (в массиве spl_line) после преобразования должно равняться начальному количетву \n (lns_num)
		return (-1);
	return (1);
}
