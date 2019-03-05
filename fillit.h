/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 02:42:13 by waddam            #+#    #+#             */
/*   Updated: 2019/03/05 02:42:34 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

typedef struct		s_flist
{
	int				x[4];
	int				y[4];
	int				max_x;
	int				max_y;
	char			letter;
	struct s_flist	*next;
}					t_flist;

int					fil_read(int fd, t_flist **begin);
t_flist				*fil_valid(char *line, int *flag, char letter);
t_flist				*fil_create_struct(char **array, char letter);
void				fil_add_struct(t_flist **begin, t_flist *list);
int					fil_len_struct(t_flist *begin);
void				fil_destroy_struct(t_flist **begin);
int					fil_core(t_flist *begin);
int					fil_max_dim(t_flist *list, int side);
int					fil_min_map(int num_ttr);
char				**fil_map(t_flist *begin, int side);
void				fil_del_map(char ***map);

#endif
