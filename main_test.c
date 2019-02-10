#include "fillit.h"

#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	int		fd1;//
	int		fd2;//
	int		fd3;//
	int		fd4;//
	int		fd5;//
	int		fd6;//
	int		fd7;//
	int		fd8;//
	int		fd9;//
	int		lns_num;
	char	*line;

	fd = 0;
	lns_num = 0;
	line = NULL;
	//if (argc == 2)
	//{
		fd = open(argv[1], O_RDONLY);
		lns_num = fil_read(fd, &line);
		if (lns_num == -1)
			ft_putendl("usage: ");
		fd1 = open(argv[2], O_RDONLY);
		lns_num = fil_read(fd1, &line);
		if (lns_num == -1)
			ft_putendl("usage: ");
		fd2 = open(argv[3], O_RDONLY);
		lns_num = fil_read(fd2, &line);
		if (lns_num == -1)
			ft_putendl("usage: ");
		fd3 = open(argv[4], O_RDONLY);
		lns_num = fil_read(fd3, &line);
		if (lns_num == -1)
			ft_putendl("usage: ");
		fd4 = open(argv[5], O_RDONLY);
		lns_num = fil_read(fd4, &line);
		if (lns_num == -1)
			ft_putendl("usage: ");
		fd5 = open(argv[6], O_RDONLY);
		lns_num = fil_read(fd5, &line);
		if (lns_num == -1)
			ft_putendl("usage: ");
		fd6 = open(argv[7], O_RDONLY);
		lns_num = fil_read(fd6, &line);
		if (lns_num == -1)
			ft_putendl("usage: ");
		fd7 = open(argv[8], O_RDONLY);
		lns_num = fil_read(fd7, &line);
		if (lns_num == -1)
			ft_putendl("usage: ");
		fd8 = open(argv[8], O_RDONLY);
		lns_num = fil_read(fd8, &line);
		if (lns_num == -1)
			ft_putendl("usage: ");
		fd9 = open(argv[10], O_RDONLY);
		lns_num = fil_read(fd9, &line);
		if (lns_num == -1)
			ft_putendl("usage: ");
		printf("%d\n%s\n", lns_num, line);
		//fil_valid(lns_num, line);
		printf("%d\n", fil_valid(lns_num, line));
		close(fd);
	//}
	//else
	//	ft_putendl("usage: ");
	return (0);
}
