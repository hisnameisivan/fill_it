#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

# include <stdio.h> //!!!!!

int		fil_read(int fd, char **line);
int		fil_valid(int lns_num, char *line, char ***array);

#endif
