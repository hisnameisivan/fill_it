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
	while ((*map)[i + dy])
	{
		while ((*map)[i + dy][j + dx])
		{
			if (dx + list->max_x > side)
			{
				dy++;
				dx = 0;
				i = 0;
				j = 0;
			}
			if (dy + list->max_y > side)
				return (-1);
			if ((*map)[i + dy + list->y[0]][j + dx + list->x[0]] == '.' \
			&& (*map)[i + dy + list->y[1]][j + dx + list->x[1]] == '.' \
			&& (*map)[i + dy + list->y[2]][j + dx + list->x[2]] == '.' \
			&& (*map)[i + dy + list->y[3]][j + dx + list->x[3]] == '.')
			{
				(*map)[i + dy + list->y[0]][j + dx + list->x[0]] = list->letter;
				(*map)[i + dy + list->y[1]][j + dx + list->x[1]] = list->letter;
				(*map)[i + dy + list->y[2]][j + dx + list->x[2]] = list->letter;
				(*map)[i + dy + list->y[3]][j + dx + list->x[3]] = list->letter;
				return (1);
			}
			else
			{
				if (j + dx < side)
				{
					dx++;
					j--;
				}
			}
			j++;
		}
		i++;
	}
	return (-1);
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
	int		algo;

	algo = 0;
	temp = begin;
	side = fil_max_dim(temp, fil_min_map(fil_len_struct(begin)));
	map = fil_map(begin, side);
	while (temp)
	{
		algo = fil_algo(temp, side, &map);
		if (algo == -1)
		{
			//del map утечка
			side++;
			map = fil_map(begin, side);
			temp = begin;
			continue ;
		}
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





















/*int		fil_core(t_flist *begin)
{
	t_flist	*temp;
	char	**map;
	int		i;
	int		side;
	int		algo;

	algo = 0;
	temp = begin;
	side = fil_max_dim(temp, fil_min_map(fil_len_struct(begin)));
	map = fil_map(begin, side);
	while (temp)
	{
		algo = fil_algo(temp, side, &map);
		if (algo == -1)
		{
			//del map
			side++;
			map = fil_map(begin, side);
			temp = begin;
			continue ;
		}
		temp = temp->next;
	}
	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
	return (1);
}*/

/*int		fil_algo(t_flist *list, int side, char ***map)
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
}*/