#include "ft.h"
#include <fcntl.h>

int ft_displayfile(char *filename)
{
    int fd;
    char buf[16000];
    int rl;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return fd;
    while ((rl = read(fd, buf, 10)) == 10)
        write(1, buf, 10);
    write(1, buf, rl);
    close(fd);
    return (fd);
}