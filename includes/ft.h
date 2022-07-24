#include<string.h>
#include<errno.h>
#include <libgen.h>
#include <unistd.h>
#ifndef FT_H
# define FT_H

void ft_putchar(char c);
void ft_swap(int *a, int *b);
void ft_putstr(char *str);
int ft_strlen(char *str);
int ft_strcmp(char *s1, char *s2);
void ft_errorhandle(char * command,char* filename);
int ft_displayfile(char *filename);

#endif