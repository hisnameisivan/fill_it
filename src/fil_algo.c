/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 02:37:36 by waddam            #+#    #+#             */
/*   Updated: 2019/03/05 15:41:26 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static int	fil_check_ttr(t_flist *list, int i, int j, char **map)
{
	int		side;
	int		k;

	side = ft_strlen(map[0]);
	k = 0;
	while (k < 4)
	{
		if (j + list->x[k] >= side || i + list->y[k] >= side)
			return (0);
		k++;
	}
	if (map[i + list->y[0]][j + list->x[0]] == '.' \
	&& map[i + list->y[1]][j + list->x[1]] == '.' \
	&& map[i + list->y[2]][j + list->x[2]] == '.' \
	&& map[i + list->y[3]][j + list->x[3]] == '.')
		return (1);
	else
		return (0);
}

static void	fil_filling(t_flist *list, int i, int j, char **map)
{
	map[i + list->y[0]][j + list->x[0]] = list->letter;
	map[i + list->y[1]][j + list->x[1]] = list->letter;
	map[i + list->y[2]][j + list->x[2]] = list->letter;
	map[i + list->y[3]][j + list->x[3]] = list->letter;
}

static void	fil_del_letter(char **map, char letter)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == letter)
				map[i][j] = '.';
			j++;
		}
		i++;
	}
}

static int	fil_algo(t_flist *list, int side, char **map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (list == NULL)
		return (1);
	while (i < side)
	{
		j = 0;
		while (j < side)
		{
			if (fil_check_ttr(list, i, j, map))
			{
				fil_filling(list, i, j, map);
				if (fil_algo(list->next, side, map))
					return (1);
				fil_del_letter(map, list->letter);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int			fil_core(t_flist *begin)
{
	t_flist	*temp;
	int		i;
	int		side;
	char	**map;

	temp = begin;
	i = 0;
	side = fil_max_dim(temp, fil_min_map(fil_len_struct(begin)));
	map = fil_map(begin, side);
	while (!(fil_algo(temp, side, map)))
	{
		fil_del_map(&map);
		side++;
		map = fil_map(begin, side);
		temp = begin;
	}
	while (map[i])
	{
		ft_putendl(map[i]);
		ft_strdel(&map[i]);
		i++;
	}
	free(map);
	map = NULL;
	return (1);
}
