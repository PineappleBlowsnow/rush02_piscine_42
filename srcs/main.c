#include "ft.h"

int ft_check_arg(int argc, char **argv, char **pnbr_str, int *pfd)
{
	char *dict_name;
	if (argc == 3)
	{
		dict_name = argv[1];
		*pnbr_str = argv[2];
	}
	else if (argc == 2)
	{
		dict_name = "numbers.dict.txt";
		*pnbr_str = argv[1];
	}
	else
	{
		write(1, "Error\n", 6);
		return (0);
	}
	*pfd = open(dict_name, O_RDONLY);
	if ((*pfd) <= 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

int main(int argc, char **argv)
{
	int fd;
	char *nbr_str;
	char *dict_str;

	if (!ft_check_arg(argc, argv, &nbr_str, &fd))
		return (-1);
	dict_str = ft_read_data(fd);
	close(fd);
	


	free(dict_str);
}
