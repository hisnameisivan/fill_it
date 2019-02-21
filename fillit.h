#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

# include <stdio.h>	//!!!!!

typedef struct		s_flist
{
	char			**array;
	int				max_x;
	int				max_y;
	struct s_flist	*next;
}					t_flist;

int		fil_len_struct(t_flist *begin);
int		fil_core(t_flist *begin);
int		fil_min_map(int num_ttr);
void	fil_max_xy_struct(char **array, t_flist **list);
t_flist	*fil_create_struct(char **array, char letter);
void	fil_print_struct(t_flist *begin);		// DEMO
void	fil_print_one_struct(t_flist *list);	// DEMO
//int		fil_len_struct(t_flist *begin);
void	fil_add_struct(t_flist **begin, t_flist *list);
void	fil_shift(char ***array);
t_flist	*fil_valid(char *line, int *flag, char letter);
int		fil_read(int fd, t_flist **begin);

#endif
