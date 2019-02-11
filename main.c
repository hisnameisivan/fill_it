#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		lns_num;
	char	*line;
	char	**array;

	fd = 0;
	lns_num = 0;
	line = NULL;
	array = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		lns_num = fil_read(fd, &line);
		if (lns_num == -1)
			ft_putendl("usage: ");
		printf("%d\n%s\n", lns_num, line);
		//fil_valid(lns_num, line);
		printf("%d\n", fil_valid(lns_num, line, &array));
		free(line); // для valgrind
		close(fd);
	}
	else
		ft_putendl("usage: ");
	return (0);
}
