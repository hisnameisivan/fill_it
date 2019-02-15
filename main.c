#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fil_read(fd) == -1)
			ft_putendl("usage: ");
		close(fd);
	}
	else
		ft_putendl("usage: ");
	return (0);
}
