#include "fillit.h"

 char	*ft_strdot(size_t size)
{
	char	*temp;
	size_t	i;

	i = 0;
	if (((size + 1) == 0) || !(temp = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		temp[i] = '.';
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

int		fil_min_map(int num_ttr)
{
	int		side;

	side = 0;
	while (side * side < num_ttr)
		side++;
	return (side);
}

int		fil_max_dim(t_flist *list)
{
	if (list->max_x > list->max_y)
		return (list->max_x);
	else
		return (list->max_y);
}

int		fil_algo(t_flist *list, int side, char ***map)
{
	int		i;
	int		j;
	int		d;
	// int		k;
	// int		dx;

	i = 0;
	j = 0;
	d = 0;
	// k = 0;
	// dx = 0;
	side = 0;
	while (list->array[i] && (*map)[i])
	{
		j = 0;
		while (list->array[i][j] && (*map)[i][j + d])
		{
			if (ft_isalpha(list->array[i][j]))
			{
				if ((*map)[i][j + d] == '.')
					(*map)[i][j + d] = list->array[i][j];
				else
					break ;
			}
			j++;
		}
		if (j < side)
			d++;
		i++;
	}
	// dx++;
	// k++;
	return 1;
}

int		fil_map(t_flist *begin, int side)	// что возвращает? Проверка malloc? Возможность вписать? ТЕСТ
{
	char	**map;
	t_flist	*temp;
	int		i;
	int		max_dim;

	map = NULL;
	temp = begin;
	i = 0;
	max_dim = 0;
	if (temp)
	{
		while (temp)
		{
			if (temp->max_x > side || temp->max_y > side)
				side = fil_max_dim(temp);
			temp = temp->next;
		}
	}
	else
		return (0);
	if (!(map = (char **)malloc(sizeof(char *) * side + 1)))
		return (0);
	while (i < side)
	{
		if (!(map[i] = ft_strdot(side)))
		{
			while (i > 0)
			{
				free(map[i - 1]);
				i--;
			}
			free(map);
			return (0);
		}
		i++;
	}
	map[i] = NULL;
	temp = begin;
	while (temp)
	{
		/*while (fil_algo(temp, side, &map) == 0)
		{
			del map;
			create map + 1;
			fil_algo(temp, side + 1, &map);
		}*/
		fil_algo(temp, side, &map);
		temp = temp->next;
	}


	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}


	return 0;
}
