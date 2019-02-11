#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd = 0;
	int		ret_fil_read = 0; // lns_num
	int		ret_fil_valid = 0;
	char	*line = NULL;
	char	**array = NULL;

	argc = 1; // счетчик
	while (argc < 11)
	{
		fd = open(argv[argc], O_RDONLY);
		ret_fil_read = fil_read(fd, &line);						//чтение
		ret_fil_valid = fil_valid(ret_fil_read, line, &array);	//валидация (несколько проверок)
		ft_putnbr(argc);
		ft_putstr(" file fil_read  ");
		ret_fil_read == -1 ? ft_putendl("FAIL") : ft_putendl("SUCCES");		//наличие/отсутствие ошибок чтения
		ft_putnbr(argc);
		ft_putstr(" file fil_valid ");
		ret_fil_valid == -1 ? ft_putendl("FAIL") : ft_putendl("SUCCES");	//наличие/отсутствие ошибок валидации
		argc++;
	}
	close(fd);
	return (0);
}

/*fd = open(argv[1], O_RDONLY);
	ret_fil_read = fil_read(fd, &line);
	ret_fil_valid = fil_valid(ret_fil_read, line);
	ft_putstr("1st  file fil_read  ");
	ret_fil_read == -1 ? ft_putendl("FAIL") : ft_putendl("SUCCES");
	ft_putstr("1st  file fil_valid ");
	ret_fil_valid == -1 ? ft_putendl("FAIL") : ft_putendl("SUCCES");

	fd = open(argv[2], O_RDONLY);
	ret_fil_read = fil_read(fd, &line);
	ret_fil_valid = fil_valid(ret_fil_read, line);
	ft_putstr("2nd  file fil_read  ");
	ret_fil_read == -1 ? ft_putendl("FAIL") : ft_putendl("SUCCES");
	ft_putstr("1st  file fil_valid ");
	ret_fil_valid == -1 ? ft_putendl("FAIL") : ft_putendl("SUCCES");

	fd = open(argv[1], O_RDONLY);
	ret_fil_read = fil_read(fd, &line);
	ret_fil_valid = fil_valid(ret_fil_read, line);
	ft_putstr("1st  file fil_read  ");
	ret_fil_read == -1 ? ft_putendl("FAIL") : ft_putendl("SUCCES");
	ft_putstr("1st  file fil_valid ");
	ret_fil_valid == -1 ? ft_putendl("FAIL") : ft_putendl("SUCCES");

	ffd = open(argv[1], O_RDONLY);
	ret_fil_read = fil_read(fd, &line);
	ret_fil_valid = fil_valid(ret_fil_read, line);
	ft_putstr("1st  file fil_read  ");
	ret_fil_read == -1 ? ft_putendl("FAIL") : ft_putendl("SUCCES");
	ft_putstr("1st  file fil_valid ");
	ret_fil_valid == -1 ? ft_putendl("FAIL") : ft_putendl("SUCCES");

	fd = open(argv[1], O_RDONLY);
	ret_fil_read = fil_read(fd, &line);
	ret_fil_valid = fil_valid(ret_fil_read, line);
	ft_putstr("1st  file fil_read  ");
	ret_fil_read == -1 ? ft_putendl("FAIL") : ft_putendl("SUCCES");
	ft_putstr("1st  file fil_valid ");
	ret_fil_valid == -1 ? ft_putendl("FAIL") : ft_putendl("SUCCES");

	fd = open(argv[6], O_RDONLY);
	lns_num = fil_read(fd, &line);
	if (lns_num == -1)
		ft_putendl("6th  file fil_read FAIL");
	ft_putstr("6th  file fil_valid ");
	ft_putnbr(fil_valid(lns_num, line));
	ft_putendl("");

	fd = open(argv[7], O_RDONLY);
	lns_num = fil_read(fd, &line);
	if (lns_num == -1)
		ft_putendl("7th  file fil_read FAIL");
	ft_putstr("7th  file fil_valid ");
	ft_putnbr(fil_valid(lns_num, line));
	ft_putendl("");

	fd = open(argv[8], O_RDONLY);
	lns_num = fil_read(fd, &line);
	if (lns_num == -1)
		ft_putendl("8th  file fil_read FAIL");
	ft_putstr("8th  file fil_valid ");
	ft_putnbr(fil_valid(lns_num, line));
	ft_putendl("");

	fd = open(argv[8], O_RDONLY);
	lns_num = fil_read(fd, &line);
	if (lns_num == -1)
		ft_putendl("9th  file fil_read FAIL");
	ft_putstr("9th  file fil_valid ");
	ft_putnbr(fil_valid(lns_num, line));
	ft_putendl("");

	fd = open(argv[10], O_RDONLY);
	lns_num = fil_read(fd, &line);
	if (lns_num == -1)
		ft_putendl("10th file fil_read FAIL");
	ft_putstr("10th file fil_valid ");
	ft_putnbr(fil_valid(lns_num, line));
	ft_putendl("");*/

	//printf("%d\n%s\n", lns_num, line);
	//printf("%d\n", fil_valid(lns_num, line));