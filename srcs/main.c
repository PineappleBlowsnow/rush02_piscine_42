#include "ft.h"

int main(int argc, char** argv) 
{ 
    (void) argc;
    (void) argv;

    int fd;

    char buf[BUFSIZE];
    fd=open("numbers.dict.txt",O_RDONLY);
    if(fd<=0){
        return (-1);
    } 
    read(fd,buf,BUFSIZE);

    close(fd);

struct number
{
    char *key;
    char *value;
    struct number *next;
};





}
