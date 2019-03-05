#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd = 0;
	int		ret_fil_read = 0;
	t_flist	*begin;

	argc = 1; // счетчик
	while (argc < 11)
	{
		fd = open(argv[argc], O_RDONLY);
		ret_fil_read = fil_read(fd, &begin);						//чтение
		ft_putnbr(argc);
		ft_putstr(" file fil_read  ");
		ret_fil_read == -1 ? ft_putendl("FAIL") : ft_putendl("SUCCES");		//наличие/отсутствие ошибок чтения
		argc++;
	}
	close(fd);
	return (0);
}
