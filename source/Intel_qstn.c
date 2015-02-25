#include<stdio.h>

int* bhardwaj(void)
{
	int a=10;
	return &a;
}


void printHello()
{
	printf("HelloWorld\n");
}

int main()
{
	int *ptr;
	ptr = bhardwaj();
	//printHello();
	printf("%d\n",*ptr);

}
