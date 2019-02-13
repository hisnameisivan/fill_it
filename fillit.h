#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

# include <stdio.h> //!!!!!

void	fil_shift(char ***array);
int		fil_valid(char *line);
int		fil_read(int fd);

#endif
