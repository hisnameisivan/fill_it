/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 02:37:49 by waddam            #+#    #+#             */
/*   Updated: 2019/03/05 15:41:32 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

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

int		fil_min_map(int num_ttr)
{
	int		side;

	side = 0;
	while (side * side < 4 * num_ttr)
		side++;
	return (side);
}

char	**fil_map(t_flist *begin, int side)
{
	char	**map;
	t_flist	*temp;
	int		i;

	map = NULL;
	temp = begin;
	i = -1;
	if (!(map = (char **)malloc(sizeof(char *) * side + 1)))
		return (NULL);
	while (++i < side)
	{
		if (!(map[i] = ft_strnew(side)))
		{
			while (i > 0)
			{
				ft_strdel(&map[i - 1]);
				i--;
			}
			ft_strdel(map);
			return (NULL);
		}
		ft_memset(map[i], 46, side);
	}
	map[i] = NULL;
	return (map);
}

void	fil_del_map(char ***map)
{
	int		i;

	i = 0;
	while ((*map)[i])
	{
		free((*map)[i]);
		(*map)[i] = NULL;
		i++;
	}
	ft_strdel(*map);
}
