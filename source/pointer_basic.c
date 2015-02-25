#include<stdio.h>
#include<stdlib.h>


int main()
{
	int a=10;
	int* p;
	p = &a;
	printf("a = %d\n",a);
	printf("&a = %d\n",&a);
	printf("p = %d\n",p);
	printf("*p = %d\n",*p);
	printf("size of integer = %d\n",sizeof(int));
	//*p = 8;
	printf("p+1 = %d\n",p+1);	
	printf("*(p+1) = %d\n",*(p+2));
	
}
