#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

# include <stdio.h> //!!!!!

typedef struct		s_flist
{
	char			**array;
	struct s_flist	*next;
}					t_flist;

void	fil_shift(char ***array);
int		fil_valid(char *line, int *flag);
int		fil_read(int fd);

#endif
