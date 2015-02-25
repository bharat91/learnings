#include<stdio.h>

int main()
{
    char a=0xAA;

    int b;

    b=(int)a;

    b=b>>4;

    printf("%x",b);


}
