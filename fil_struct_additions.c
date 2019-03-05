/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil_struct_additions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 02:14:52 by waddam            #+#    #+#             */
/*   Updated: 2019/03/05 02:26:30 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fil_add_struct(t_flist **begin, t_flist *list)
{
	t_flist	*temp;

	temp = NULL;
	if (!*begin && list)
		*begin = list;
	else if (list)
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

void	fil_destroy_struct(t_flist **begin)
{
	t_flist	*temp;

	temp = NULL;
	while (*begin)
	{
		temp = (*begin)->next;
		free(*begin);
		*begin = temp;
	}
}
