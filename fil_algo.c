#include "fillit.h"

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
	while (i < side + 1)
	{
		if (!(map[i] = (char *)malloc(sizeof(char) * side + 1)))
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

}
