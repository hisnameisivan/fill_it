#include "fillit.h"

#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	int		lns_num;
	char	*line;

	fd = 0;
	lns_num = 0;
	line = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		lns_num = fil_read(fd, &line);
		printf("%d\n%s\n", lns_num, line);
		close(fd);
	}
	else
		ft_putendl("usage: ");
	return (0);
}
