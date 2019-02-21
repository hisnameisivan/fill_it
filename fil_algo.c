#include "fillit.h"

int		fil_min_map(int num_ttr)
{
	int		side;

	side = 0;
	while (side * side < 4 * num_ttr)
		side++;
	return (side);
}

int		fil_max_dim(t_flist *list, int side)
{
	while (list)
	{
		if (list->max_x > side && list->max_x > list->max_y)
			return (list->max_x);
		else if (list->max_y > side && list->max_y > list->max_x)
			return (list->max_y);
		list = list->next;
	}
	return (side);
}

int		fil_algo(t_flist *list, int side, char ***map)
{
	int		i;
	int		j;
	int		dx;
	int		dy;

	i = 0;
	j = 0;
	dx = 0;
	dy = 0;
	while (list->array[i] && (*map)[i + dy])
	{
		if (dy + list->max_y > side)
			return (-1);
		j = 0;
		while (list->array[i][j] && (*map)[i + dy][j + dx])
		{
			if (dx + list->max_x > side)
			{
				dy++;
				dx = 0;
				i = 0;
				j = 0;
			}
			if (ft_isalpha(list->array[i][j]))
			{
				if ((*map)[i + dy][j + dx] == '.')
					(*map)[i + dy][j + dx] = list->array[i][j];
				else
					break ;
			}
			j++;
		}
		if (j + dx < side)
		{
			dx++;
			i--;
		}
		i++;
	}
	return (1);
}

char	**fil_map(t_flist *begin, int side)
{
	char	**map;
	t_flist	*temp;
	int		i;

	map = NULL;
	temp = begin;
	i = 0;
	if (!(map = (char **)malloc(sizeof(char *) * side + 1)))
		return (NULL);
	while (i < side)
	{
		if (!(map[i] = ft_strnew(side)))
		{
			while (i > 0)
			{
				free(map[i - 1]);
				i--;
			}
			free(map);
			return (NULL);
		}
		ft_memset(map[i], 46, side);
		i++;
	}
	map[i] = NULL;
	return (map);
}

int		fil_core(t_flist *begin)
{
	t_flist	*temp;
	char	**map;
	int		i;
	int		side;

	temp = begin;
	side = fil_max_dim(temp, fil_min_map(fil_len_struct(begin)));
	map = fil_map(begin, side);
	while (temp)
	{
		while (fil_algo(temp, side, &map) == -1)
		{
			//del map;
			side++;
			map = fil_map(begin, side);
			fil_algo(temp, side + 1, &map);
		}
		//fil_algo(temp, side, &map);
		temp = temp->next;
	}
	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
	return (1);
}