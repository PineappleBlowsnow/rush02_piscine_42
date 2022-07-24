#include "ft.h"

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    int fd;
    t_dl dict_data;
    t_dl cur;
    char *nbr_str;
    char *dict_name;
    if (argc == 3)
    {
        dict_name = argv[1];
        nbr_str = argv[2];
    }
    else if (argc == 2)
    {
        dict_name = "numbers.dict.txt";
        nbr_str = argv[1];
    }
    else
    {
        write(1, "Error\n", 6);
        return (-1);
    }

    char buf[BUFSIZE];
    fd = open(dict_name, O_RDONLY);
    if (fd <= 0)
    {
        return (-1);
    }

    read(fd, buf, BUFSIZE);

    close(fd);
}
