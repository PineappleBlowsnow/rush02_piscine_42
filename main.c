#include <fcntl.h> 
#include<ft.h>
#include<stdio.h>
#include "ft.h"

int main() 
{ 

    FILE *fp; 
    fp = fopen("numbers.dict.txt", "r");


    fclose(fp);

struct number
{
    char *key;
    char *value;
    struct number *next;
};





}
