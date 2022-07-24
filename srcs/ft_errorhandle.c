#include<ft.h>
void ft_errorhandle(char * command,char* filename)
{
    ft_putstr(basename(command));
    ft_putstr(": ");
    ft_putstr(filename);
    ft_putstr(": ");
    ft_putstr(strerror(errno));
    ft_putstr("\n");
}