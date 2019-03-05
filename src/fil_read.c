/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 01:15:53 by waddam            #+#    #+#             */
/*   Updated: 2019/03/05 15:41:37 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int		fil_read(int fd, t_flist **begin)
{
	int		ret;
	int		flag_sn;
	char	letter;
	char	buf[21 + 1];
	t_flist	*temp;

	ret = 0;
	flag_sn = 0;
	letter = 'A';
	temp = NULL;
	while ((ret = read(fd, buf, 21)) > 0)
	{
		buf[ret] = '\0';
		if (!(temp = fil_valid(buf, &flag_sn, letter)))
			return (-1);
		fil_add_struct(begin, temp);
		letter++;
	}
	if (ret == -1 || flag_sn == 1 || (*buf == '\0' && ret == 0))
		return (-1);
	return (1);
}
