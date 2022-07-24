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
		return (0);
	if (!ft_isnumeric(*pnbr_str))
		return (0);
	*pfd = open(dict_name, O_RDONLY);
	if ((*pfd) <= 0)
		return (0);
	return (1);
}
char *ft_trim_zero(nbr_str){
	while((*nbr_str)=='0')
		nbr_str++;
	return nbr_str;
}
int main(int argc, char **argv)
{
	int fd;
	char *nbr_str;
	char *dict_str;
	char *std_dict_str;
	int nbr_size;

	if (!ft_check_arg(argc, argv, &nbr_str, &fd))
	{
		write(1, "Error\n", 6);
		return (-1);
	}

	dict_str = ft_read_data(fd);
	close(fd);
	nbr_str=ft_trim_zero(nbr_str);
	nbr_size=ft_strlen(nbr_str);
	
	free(dict_str);
}
