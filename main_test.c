#include "fillit.h"

#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd = 0;
	int		lns_num = 0;
	char	*line = NULL;

	argc = 0;

		fd = open(argv[1], O_RDONLY);
		lns_num = fil_read(fd, &line);
		if (lns_num == -1)
			ft_putendl("1st file fil_read FAIL");
		ft_putstr("1st file fil_valid ");
		ft_putnbr(fil_valid(lns_num, line));
		ft_putendl("");

		fd = open(argv[2], O_RDONLY);
		lns_num = fil_read(fd, &line);
		if (lns_num == -1)
			ft_putendl("2nd file fil_read FAIL");
		ft_putstr("2nd file fil_valid ");
		ft_putnbr(fil_valid(lns_num, line));
		ft_putendl("");

		fd = open(argv[3], O_RDONLY);
		lns_num = fil_read(fd, &line);
		if (lns_num == -1)
			ft_putendl("3rd file fil_read FAIL");
		ft_putstr("3rd file fil_valid ");
		ft_putnbr(fil_valid(lns_num, line));
		ft_putendl("");

		fd = open(argv[4], O_RDONLY);
		lns_num = fil_read(fd, &line);
		if (lns_num == -1)
			ft_putendl("4th file fil_read FAIL");
		ft_putstr("4th file fil_valid ");
		ft_putnbr(fil_valid(lns_num, line));
		ft_putendl("");

		fd = open(argv[5], O_RDONLY);
		lns_num = fil_read(fd, &line);
		if (lns_num == -1)
			ft_putendl("5th file fil_read FAIL");
		ft_putstr("5th file fil_valid ");
		ft_putnbr(fil_valid(lns_num, line));
		ft_putendl("");

		fd = open(argv[6], O_RDONLY);
		lns_num = fil_read(fd, &line);
		if (lns_num == -1)
			ft_putendl("6th file fil_read FAIL");
		ft_putstr("6th file fil_valid ");
		ft_putnbr(fil_valid(lns_num, line));
		ft_putendl("");

		fd = open(argv[7], O_RDONLY);
		lns_num = fil_read(fd, &line);
		if (lns_num == -1)
			ft_putendl("7th file fil_read FAIL");
		ft_putstr("7th file fil_valid ");
		ft_putnbr(fil_valid(lns_num, line));
		ft_putendl("");

		fd = open(argv[8], O_RDONLY);
		lns_num = fil_read(fd, &line);
		if (lns_num == -1)
			ft_putendl("8th file fil_read FAIL");
		ft_putstr("8th file fil_valid ");
		ft_putnbr(fil_valid(lns_num, line));
		ft_putendl("");

		fd = open(argv[8], O_RDONLY);
		lns_num = fil_read(fd, &line);
		if (lns_num == -1)
			ft_putendl("9th file fil_read FAIL");
		ft_putstr("9th file fil_valid ");
		ft_putnbr(fil_valid(lns_num, line));
		ft_putendl("");

		fd = open(argv[10], O_RDONLY);
		lns_num = fil_read(fd, &line);
		if (lns_num == -1)
			ft_putendl("10th file fil_read FAIL");
		ft_putstr("10th file fil_valid ");
		ft_putnbr(fil_valid(lns_num, line));
		ft_putendl("");

		//printf("%d\n%s\n", lns_num, line);
		//printf("%d\n", fil_valid(lns_num, line));
		close(fd);

	return (0);
}
