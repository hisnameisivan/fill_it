/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 02:14:29 by waddam            #+#    #+#             */
/*   Updated: 2019/03/05 15:41:46 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static void	fil_max_xy_struct(char **array, t_flist **list)
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

static int	fil_x_struct(char **array, int p)
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

static int	fil_y_struct(char **array, int q)
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

t_flist		*fil_create_struct(char **array, char letter)
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
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (temp);
}
