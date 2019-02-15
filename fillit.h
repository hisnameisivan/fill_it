#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

# include <stdio.h>	//!!!!!

typedef struct		s_flist
{
	char			**array;
	struct s_flist	*next;
}					t_flist;

t_flist	*fil_crt_struct(char **array);
void	fil_print_struct(t_flist *begin);		// DEMO
void	fil_print_one_struct(t_flist *list);	// DEMO
void	fil_add_struct(t_flist **begin, t_flist *list);
void	fil_shift(char ***array);
int		fil_valid(char *line, int *flag);
int		fil_read(int fd);

#endif
