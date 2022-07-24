#include "ft.h"
char *readdata(int fd)
{
    char *result;
    t_dl dl = malloc(sizeof(*dl));
    t_dl curr = dl;
    t_dl pre=dl;
    int read_size;
    read_size = read(fd, curr->data, BUFSIZE);
    curr->data[read_size] = '\0';
    curr->pre=0;
    int totalsize;

    totalsize=read_size;

    while (read_size == BUFSIZE)
    {
        curr=malloc(sizeof(*curr));
        read_size = read(fd, curr->data, BUFSIZE);
        curr->data[read_size] = '\0';
        curr->pre=pre;
        pre->next=curr;
        pre=curr;
        totalsize+=read_size;
    }    
    curr->next=0;
    result=malloc(sizeof(*result)*totalsize);
    result[0]=0;
   
    pre=0;
    curr=dl;
    while(curr){
        if(pre)free(pre);
        ft_strcat(result,curr->data);
        pre=curr;
        curr=curr->next;

    }
    free(pre);
    return result;
}