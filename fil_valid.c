/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil_valid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 01:15:35 by waddam            #+#    #+#             */
/*   Updated: 2019/03/05 03:14:22 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	fil_count_char(char *line, int *flag)
{
	int		i;
	int		*count;

	i = -1;
	count = ft_memalloc(12);
	while (line[++i])
	{
		if (line[i] == '#')
			count[0]++;
		else if (line[i] == '.')
			count[1]++;
		else if (line[i] == '\n')
		{
			count[2]++;
			if (!((i + 1) % 5 == 0 || i == 20))
				return (0);
		}
		else
			return (0);
	}
	if ((count[0] != 4) || (count[1] != 12) || (count[2] < 4 || count[2] > 5))
		return (0);
	*flag = (count[2] == 5 ? 1 : 0);
	ft_memdel((void *)&count);
	return (1);
}

static int	fil_check_connections(char *line)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == '#' && i < 14 && line[i + 5] == '#')
			count++;
		if (line[i] == '#' && i > 4 && line[i - 5] == '#')
			count++;
		if (line[i] == '#' && i % 5 != 0 && line[i - 1] == '#')
			count++;
		if (line[i] == '#' && i % 5 != 3 && line[i + 1] == '#')
			count++;
		i++;
	}
	return (count);
}

static void	fil_shift_horizontal(char **array)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] == '#')
				break ;
			j++;
		}
		if (j == 4 && i == 0)
		{
			ft_memcpy(array[i], array[i + 1], 4);
			ft_memcpy(array[i + 1], array[i + 2], 4);
			ft_memcpy(array[i + 2], array[i + 3], 4);
			ft_memcpy(array[i + 3], "....", 4);
			i = -1;
		}
		i++;
	}
}

static void	fil_shift_vertical(char **array)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((array[0][0] == '.') && (array[1][0] == '.')\
		&& (array[2][0] == '.') && (array[3][0] == '.'))
	{
		i = 0;
		while (array[i])
		{
			j = 0;
			while (array[i][j])
			{
				array[i][j] = array[i][j + 1];
				j++;
			}
			array[i][3] = '.';
			i++;
		}
	}
}

t_flist		*fil_valid(char *line, int *flag, char letter)
{
	int		i;
	char	**spl_line;

	i = 0;
	spl_line = NULL;
	if (letter >= '[')
		return (NULL);
	if (!(fil_count_char(line, flag)))
		return (NULL);
	if (fil_check_connections(line) < 6)
		return (NULL);
	if (!(spl_line = ft_strsplit(line, '\n')))
		return (NULL);
	fil_shift_horizontal(spl_line);
	fil_shift_vertical(spl_line);
	return (fil_create_struct(spl_line, letter));
}
