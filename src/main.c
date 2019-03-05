/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 01:16:03 by waddam            #+#    #+#             */
/*   Updated: 2019/03/05 15:41:53 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int		main(int argc, char **argv)
{
	int		fd;
	t_flist	*begin;

	begin = NULL;
	if (argc == 2)
	{
		if (!(fd = open(argv[1], O_RDONLY)))
			return (-1);
		if (fil_read(fd, &begin) == -1)
		{
			ft_putendl("error");
			fil_destroy_struct(&begin);
		}
		if (fil_core(begin) == -1)
		{
			fil_destroy_struct(&begin);
			exit(-1);
		}
		fil_destroy_struct(&begin);
		if (!(close(fd)))
			return (-1);
	}
	else
		ft_putendl("usage: ./fillit valid_map_file");
	return (0);
}
