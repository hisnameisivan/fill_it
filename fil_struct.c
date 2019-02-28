#include "fillit.h"

void	fil_max_xy_struct(char **array, t_flist **list)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	(*list)->max_x = 0;
	(*list)->max_y = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] == '#')
			{
				if ((*list)->max_x < j + 1)
					(*list)->max_x = j + 1;
				if ((*list)->max_y < i + 1)
					(*list)->max_y = i + 1;
			}
			j++;
		}
		i++;
	}
}

int		fil_x_struct(char **array, int p)
{
	int		count;
	int		i;
	int		j;
	int		x;

	count = 0;
	i = 0;
	j = 0;
	x = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] == '#')
			{
				if (p == count)
					x = j;
				count++;
			}
			j++;
		}
		i++;
	}
	return (x);
}

int		fil_y_struct(char **array, int q)
{
	int		count;
	int		i;
	int		j;
	int		y;

	count = 0;
	i = 0;
	j = 0;
	y = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] == '#')
			{
				if (q == count)
					y = i;
				count++;
			}
			j++;
		}
		i++;
	}
	return (y);
}

t_flist	*fil_create_struct(char **array, char letter)
{
	int		i;
	t_flist	*temp;

	i = 0;
	if (!(temp = (t_flist *)malloc(sizeof(t_flist))))
		return (NULL);
	while (i < 4)
	{
		(temp->x)[i] = fil_x_struct(array, i);
		(temp->y)[i] = fil_y_struct(array, i);
		i++;
	}
	fil_max_xy_struct(array, &temp);
	temp->letter = letter;
	temp->next = NULL;
	return (temp);
}

void	fil_add_struct(t_flist **begin, t_flist *list)	// переделать, если нет begin
{
	t_flist	*temp;

	if (begin && list)
	{
		temp = *begin;
		while (temp->next)
			temp = temp->next;
		temp->next = list;
	}
}

int		fil_len_struct(t_flist *begin)
{
	int		len;

	len = 0;
	if (begin)
	{
		while (begin)
		{
			len++;
			begin = begin->next;
		}
	}
	return (len);
}

















/*t_flist	*fil_create_struct1(char **array, char letter)
{
	int		i;
	int		j;
	t_flist	*temp;

	i = 0;
	j = 0;
	if (!(temp = (t_flist *)malloc(sizeof(t_flist))))
		return (NULL);
	if (!array)
	{
		temp->array = NULL;
		temp->max_x = 0;
		temp->max_y = 0;
		temp->next = NULL;
	}
	else
	{
		if (!(temp->array = (char **)malloc(sizeof(char *) * 5)))
		{
			free(temp);
			return (NULL);
		}
		(temp->array)[4] = NULL;
		while (i < 4)
		{
			if (!(temp->array[i] = (char *)malloc(sizeof(char) * 5)))
			{
				while (i > 0)
				{
					free((temp->array)[i - 1]);
					i--;
				}
				free(temp->array);
				free(temp);
				return (NULL);
			}
			//ft_memcpy((temp->array)[i], array[i], 5);
			j = 0;
			while (j < 5)
			{
				if (array[i][j] == '#')
					(temp->array)[i][j] = letter;
				else
					(temp->array)[i][j] = array[i][j];
				j++;
			}
			i++;
		}
		fil_max_xy_struct(array, &temp);
		temp->next = NULL;
	}
	return (temp);
}*/
