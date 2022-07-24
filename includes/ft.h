
#ifndef FT_H
#define FT_H
#include <string.h>
#include <errno.h>
#include <libgen.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#define BUFSIZE (1024)

struct s_nlist
{                       /* table entry: */
    struct s_nlist *next; /* next entry in chain */
    char *name;         /* defined name */
    char *defn;         /* replacement text */
};

typedef struct s_datalist
{
    struct s_datalist *next;
    struct s_datalist *pre;
    char data[BUFFSIZE + 1];
}* t_dl;

struct number
{
    char *key;
    char *value;
    struct number *next;
};

char *ft_read_data(int fd); // using s_datalist to store read data and finally add to a str malloced
char *ft_strcat(char *dest, char *src);
void ft_putchar(char c);
void ft_swap(int *a, int *b);
void ft_putstr(char *str);
int ft_strlen(char *str);
int ft_strcmp(char *s1, char *s2);

#endif