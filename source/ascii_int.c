#include<stdio.h>
#include<string.h>
#include <math.h>

int main()
{

	char* a = "10";
	int i,len;
	double sum=0.0;
	printf("%d\n",*(a+1));

	len = strlen(a);
	i=0;
	while(i<len)
	{
		sum += pow(10.,(len-i)) * (*(a+i) - '0'); 
	}
	printf("sum = %f\n",sum);

	return 0;
}
